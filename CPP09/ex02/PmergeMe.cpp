#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &toCopy)
{
    *this = toCopy;
}

PmergeMe::PmergeMe(char **input, unsigned long n)
{
    for (unsigned long i = 0; i < n; i ++)
    {
        if (!this->acceptNumbers(input[i]))
        {
            std::cerr << "Error" << std::endl;
            throw parseError(); 
        }
        this->_input.push_back(this->returnNumbers(input[i]));
        this->_qinput.push_back(this->returnNumbers(input[i]));  
    }
}

PmergeMe &PmergeMe::operator=(const PmergeMe &toCopy)
{
    if (this == &toCopy)
        return (*this);
    this->_input = toCopy._input;
    this->_qinput = toCopy._qinput;
    return (*this);
}

bool PmergeMe::acceptNumbers(std::string str)
{
    unsigned long i = 0;

    if (str == "")
        return (false);

    for (; i < str.length(); i ++)
        if (!isdigit(str[i]))
            return (false);
    
    long n = std::strtol(str.c_str(), NULL, 10);
    
    if (n > 2147483647)
        return (false);
    return (true);
}

int PmergeMe::returnNumbers(std::string str)
{
    return (static_cast<int>(std::strtol(str.c_str(), NULL, 10)));
}

void PmergeMe::execInput()
{
    std::vector<int> solved = this->_input;
    std::deque<int> qsolved = this->_qinput;

    std::cout << std::endl << "// vector:" << std::endl;
    clock_t start = clock();
    if (this->_input.size() <= 3)
    {
        clock_t end = clock();
        this->miniMerge(solved);
        this->printResult(solved);
        std::cout << "Time to process a range of " << this->_input.size() << " elements with std::vector : " << std::fixed << std::setprecision(0) << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
        std::cout << std::endl << "// deque:" << std::endl;
        start = clock();
        this->qminiMerge(qsolved);
        end = clock();
        this->qprintResult(qsolved);
        std::cout << "Time to process a range of " << this->_input.size() << " elements with std::deque : " << std::fixed << std::setprecision(0) << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
        return ;
    }

    this->execRecursiveRev(solved, this->execRecursive(solved, 1));
    clock_t end = clock();
    this->printResult(solved);
    std::cout << "Time to process a range of " << this->_input.size() << " elements with std::vector : " << std::fixed << std::setprecision(0) << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;

    std::cout << std::endl << "// deque:" << std::endl;
    start = clock();
    this->qexecRecursiveRev(qsolved, this->qexecRecursive(qsolved, 1));
    end = clock();
    this->qprintResult(qsolved);
    std::cout << "Time to process a range of " << this->_qinput.size() << " elements with std::deque : " << std::fixed << std::setprecision(0) << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
}

void PmergeMe::printResult(std::vector<int> solved)
{
    std::cout << "Before:   ";
    for (unsigned long i = 0; i < this->_input.size(); i ++)
        std::cout << this->_input[i] << " ";
    std::cout << std::endl;
    std::cout << "After:    ";
    for (unsigned long i = 0; i < solved.size(); i ++)
        std::cout << solved[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::miniMerge(std::vector<int> &sequence)
{
    if (sequence.size() == 1)
        return ;
    
    if (sequence[0] > sequence[1])
        this->swapper(sequence.begin(), sequence.begin() + 1, 1);

    if (sequence.size() == 2)
        return ;

    std::vector<int> temp = this->inserterNew(sequence, 1, this->genJackstal(1));
    this->binarySearch(sequence, temp, 0, 1);
}

unsigned long PmergeMe::execRecursive(std::vector<int> &sequence, unsigned long pair)
{
    unsigned long n = pair - 1;
    unsigned long sum;

    if (pair == 1)
        sum = 0;
    else
        sum = pair - 1;

    if (n > (sequence.size() / 2))
        return (pair / 2);

    while (n <= sequence.size() - pair - 1)
    {
        if (sequence[n] > sequence[n + pair])
            this->swapper((sequence.begin()) + n - sum, (sequence.begin()) + (n + pair) - sum, pair);
        n += (pair * 2);
    }

    return (this->execRecursive(sequence, pair * 2));
}

void PmergeMe::execRecursiveRev(std::vector<int> &sequence, unsigned long pair)
{
    std::vector<unsigned long> jackos;
    unsigned long s;

    s = (sequence.size() / 2);
    if (sequence.size() % pair * 2 != 0)
        s ++;
    if ((sequence.size() / pair) % 2 != 0)
        s += pair;

    if (s > 0)
        jackos = this->genJackstal((s / pair) - 1);
    else
        jackos = this->genJackstal(s / pair);

    std::vector<int> temp;

    if (jackos[0] == 0)
    {
        this->execRecursiveRev(sequence, pair / 2);
        return ;
    }

    temp = this->inserterNew(sequence, pair, jackos);

    for (unsigned long i = 0; i < temp.size(); i += pair)
        this->binarySearch(sequence, temp, i + pair - 1, pair);
    
    if (pair > 1)
        this->execRecursiveRev(sequence, pair / 2);
}

void PmergeMe::binarySearch(std::vector<int> &sequence, std::vector<int> &element, unsigned long pos, unsigned long pair)
{
    unsigned long o = sequence.size() / pair / 2;
    unsigned long u = sequence.size() / pair / 2;

    while (element[pos] < sequence[(o * pair) - 1] || element[pos] > sequence[(o * pair) + pair - 1])
    {
        if (o >= (sequence.size() + pair - 1) / pair)
        {
            o = sequence.size() / pair;
            break;
        }

        if (element[pos] < sequence[(o * pair) - 1])
        {
            if (u > 1)
                u /= 2;
            o -= u;
        }
        else
        {
            if (u > 1)
                u /= 2;
            o += u;
        }
        if (o == 0)
            break ;
    }

    if (o != 0)
        this->inserter(sequence, element, pair, o * pair, pos - pair + 1);
    else
        this->inserter(sequence, element, pair, 0, pos - pair + 1);    
}

void PmergeMe::swapper(std::vector<int>::iterator a, std::vector<int>::iterator b, unsigned long pair)
{
    for (unsigned int n = 0; n < pair; n ++)
        std::swap(*(a + n), *(b + n));
}

void PmergeMe::inserter(std::vector<int> &a, std::vector<int> &b, unsigned long pair, unsigned long pos1, unsigned long pos2)
{
    unsigned int n;
    std::vector<int> temp;

    for (n = 0; n < pair; n ++)
        temp.push_back(b[pos2 + n]);

    a.insert(a.begin() + pos1, temp.begin(), temp.begin() + n);
}

std::vector<int> PmergeMe::inserterNew(std::vector<int> &a, unsigned long pair, std::vector<unsigned long> jackos)
{
    unsigned long prejack = 0;
    unsigned long sumjack = 0;
    unsigned long i = 0;
    std::vector<int> temp;

    while (jackos.begin() + i < jackos.end())
    {
        prejack = jackos[i];
        for (; prejack > 0; prejack--)
        {
            for (unsigned long n = 0; n < pair; n ++)
            {
                temp.push_back(a[((pair * 2) + ((pair * 2) * (prejack + sumjack)) - (pair * 2)) + n]);
            }
        }
        sumjack += jackos[i];
        i ++;
    }

    for (unsigned long count = 0; count < sumjack; count ++)
    {
        for (unsigned long n = 0; n < pair; n ++)
            a.erase(a.begin() + (pair * 2) + ((sumjack - count) * (pair * 2)) - (pair * 2));
    }

    return (temp);
}

std::vector<unsigned long> PmergeMe::genJackstal(unsigned long n)
{
    std::vector<unsigned long> toret;
    std::vector<unsigned long> arr;
    unsigned long max = 0;
    unsigned long save;

    arr.push_back(3);
    arr.push_back(1);

    while (max + arr[0] - arr[1] < n)
    {
        toret.push_back(arr[0] - arr[1]);
        max += arr[0] - arr[1];
        save = arr[0];
        arr[0] = arr[0] + (arr[1] * 2);
        arr[1] = save;
    }

     toret.push_back(n - max);

    return (toret);
}





void PmergeMe::qminiMerge(std::deque<int> &sequence)
{
    if (sequence.size() == 1)
        return ;
    
    if (sequence[0] > sequence[1])
        this->qswapper(sequence.begin(), sequence.begin() + 1, 1);

    if (sequence.size() == 2)
        return ;

    std::deque<int> temp = this->qinserterNew(sequence, 1, this->qgenJackstal(1));
    this->qbinarySearch(sequence, temp, 0, 1);
}

unsigned long PmergeMe::qexecRecursive(std::deque<int> &sequence, unsigned long pair)
{
    unsigned long n = pair - 1;
    unsigned long sum;

    if (pair == 1)
        sum = 0;
    else
        sum = pair - 1;

    if (n > (sequence.size() / 2))
        return (pair / 2);

    while (n <= sequence.size() - pair - 1)
    {
        if (sequence[n] > sequence[n + pair])
            this->qswapper((sequence.begin()) + n - sum, (sequence.begin()) + (n + pair) - sum, pair);
        n += (pair * 2);
    }

    return (this->qexecRecursive(sequence, pair * 2));
}

void PmergeMe::qexecRecursiveRev(std::deque<int> &sequence, unsigned long pair)
{
    std::deque<unsigned long> jackos;
    unsigned long s;

    s = (sequence.size() / 2);
    if (sequence.size() % pair * 2 != 0)
        s ++;
    if ((sequence.size() / pair) % 2 != 0)
        s += pair;

    if (s > 0)
        jackos = this->qgenJackstal((s / pair) - 1);
    else
        jackos = this->qgenJackstal(s / pair);

    std::deque<int> temp;

    if (jackos[0] == 0)
    {
        this->qexecRecursiveRev(sequence, pair / 2);
        return ;
    }

    temp = this->qinserterNew(sequence, pair, jackos);

    for (unsigned long i = 0; i < temp.size(); i += pair)
        this->qbinarySearch(sequence, temp, i + pair - 1, pair);
    
    if (pair > 1)
        this->qexecRecursiveRev(sequence, pair / 2);
}

void PmergeMe::qbinarySearch(std::deque<int> &sequence, std::deque<int> &element, unsigned long pos, unsigned long pair)
{
    unsigned long o = sequence.size() / pair / 2;
    unsigned long u = sequence.size() / pair / 2;

    while (element[pos] < sequence[(o * pair) - 1] || element[pos] > sequence[(o * pair) + pair - 1])
    {
        if (o >= (sequence.size() + pair - 1) / pair)
        {
            o = sequence.size() / pair;
            break;
        }

        if (element[pos] < sequence[(o * pair) - 1])
        {
            if (u > 1)
                u /= 2;
            o -= u;
        }
        else
        {
            if (u > 1)
                u /= 2;
            o += u;
        }
        if (o == 0)
            break ;
    }

    if (o != 0)
        this->qinserter(sequence, element, pair, o * pair, pos - pair + 1);
    else
        this->qinserter(sequence, element, pair, 0, pos - pair + 1);    
}

void PmergeMe::qswapper(std::deque<int>::iterator a, std::deque<int>::iterator b, unsigned long pair)
{
    for (unsigned int n = 0; n < pair; n ++)
        std::swap(*(a + n), *(b + n));
}

void PmergeMe::qinserter(std::deque<int> &a, std::deque<int> &b, unsigned long pair, unsigned long pos1, unsigned long pos2)
{
    unsigned int n;
    std::deque<int> temp;

    for (n = 0; n < pair; n ++)
        temp.push_back(b[pos2 + n]);

    a.insert(a.begin() + pos1, temp.begin(), temp.begin() + n);
}

std::deque<int> PmergeMe::qinserterNew(std::deque<int> &a, unsigned long pair, std::deque<unsigned long> jackos)
{
    unsigned long prejack = 0;
    unsigned long sumjack = 0;
    unsigned long i = 0;
    unsigned long count = 0;
    std::deque<int> temp;
    std::deque<int>::iterator it = a.begin();

    while (jackos.begin() + i < jackos.end())
    {
        prejack = jackos[i];
        for (; prejack > 0; prejack--)
        {
            for (unsigned long n = 0; n < pair; n ++)
            {
                temp.push_back(a[((pair * 2) + ((pair * 2) * (prejack + sumjack)) - (pair * 2)) + n - count]);
                it = a.begin();
                std::advance(it, ((pair * 2) + ((pair * 2) * (prejack + sumjack)) - (pair * 2)) + n - count);
                a.erase(it);
                count ++;
            }
        }
        sumjack += jackos[i];
        i ++;
    }

    for (unsigned long count = 0; count < sumjack; count ++)
    {
        for (unsigned long n = 0; n < pair; n ++)
        {

        }
    }

    return (temp);
}

std::deque<unsigned long> PmergeMe::qgenJackstal(unsigned long n)
{
    std::deque<unsigned long> toret;
    std::deque<unsigned long> arr;
    unsigned long max = 0;
    unsigned long save;

    arr.push_back(3);
    arr.push_back(1);

    while (max + arr[0] - arr[1] < n)
    {
        toret.push_back(arr[0] - arr[1]);
        max += arr[0] - arr[1];
        save = arr[0];
        arr[0] = arr[0] + (arr[1] * 2);
        arr[1] = save;
    }

     toret.push_back(n - max);

    return (toret);
}

void PmergeMe::qprintResult(std::deque<int> solved)
{
    std::cout << "Before:   ";
    for (unsigned long i = 0; i < this->_qinput.size(); i ++)
        std::cout << this->_qinput[i] << " ";
    std::cout << std::endl;
    std::cout << "After:    ";
    for (unsigned long i = 0; i < solved.size(); i ++)
        std::cout << solved[i] << " ";
    std::cout << std::endl;
}

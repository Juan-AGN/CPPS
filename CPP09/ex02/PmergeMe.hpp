#ifndef  PmergeMe_HPP
# define  PmergeMe_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <string>
# include <cstdlib>
# include <algorithm>
# include <iostream>
# include <sys/time.h>
# include <iomanip>

class   PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(char **input, unsigned long n);
        PmergeMe(const PmergeMe &toCopy);
        PmergeMe &operator=(const PmergeMe &toCopy);
    
        void execInput();

        class parseError : public std::exception {
        public:
            virtual const char *what() const throw() {
                return ("PmergeMe: Parse error");
            }
        };

    private:
        std::vector<int> _input;
        std::deque<int> _qinput;

        bool acceptNumbers(std::string str);
        int returnNumbers(std::string str);
        unsigned long execRecursive(std::vector<int> &sequence, unsigned long pair);
        std::vector<int> solveVectors(std::vector<int> sequence, std::vector<int> groupa);
        void swapper(std::vector<int>::iterator a, std::vector<int>::iterator b, unsigned long pair);
        void printResult(std::vector<int> solved);
        std::vector<unsigned long> genJackstal(unsigned long n);
        void inserter(std::vector<int> &a, std::vector<int> &b, unsigned long pair, unsigned long posa, unsigned long posb);
        void execRecursiveRev(std::vector<int> &sequence, unsigned long pair);
        void binarySearch(std::vector<int> &sequence, std::vector<int> &element, unsigned long pos, unsigned long pair);
        std::vector<int> inserterNew(std::vector<int> &a, unsigned long pair, std::vector<unsigned long> jackos);
        void miniMerge(std::vector<int> &sequence);


        bool qacceptNumbers(std::string str);
        int qreturnNumbers(std::string str);
        void qprintResult(std::deque<int> solved);
        unsigned long qexecRecursive(std::deque<int> &sequence, unsigned long pair);
        std::deque<int> lsolvedeques(std::deque<int> sequence, std::deque<int> groupa);
        void qswapper(std::deque<int>::iterator a, std::deque<int>::iterator b, unsigned long pair);
        std::deque<unsigned long> qgenJackstal(unsigned long n);
        void qinserter(std::deque<int> &a, std::deque<int> &b, unsigned long pair, unsigned long posa, unsigned long posb);
        void qexecRecursiveRev(std::deque<int> &sequence, unsigned long pair);
        void qbinarySearch(std::deque<int> &sequence, std::deque<int> &element, unsigned long pos, unsigned long pair);
        std::deque<int> qinserterNew(std::deque<int> &a, unsigned long pair, std::deque<unsigned long> jackos);
        void qminiMerge(std::deque<int> &sequence);
};

#endif
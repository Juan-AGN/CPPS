#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void swap(T &tone, T &ttwo)
{
    T copy = tone;

    tone = ttwo;
    ttwo = copy;
}

template <typename T> T min(T tone, T ttwo)
{
    return ((ttwo <= tone) ? ttwo : tone);
}

template <typename T> T max(T tone, T ttwo)
{
    return ((ttwo >= tone) ? ttwo : tone);
}

#endif
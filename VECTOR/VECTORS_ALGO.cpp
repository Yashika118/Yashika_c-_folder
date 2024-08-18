

class vector
{
    int cs;
    int ms;
    int *arr; // here arr is a pointer

public:
    vector()
    {
        cs = 0;
        ms = 1;
        arr = new int[ms];
    }

    void push_back(int data)
    {
        if (cs == ms)
        { //--> arr is full
            int *oldarr = arr;
            arr = new int[2 * ms];
            ms = 2 * ms;
            for (int i = 0; i < cs; i++)
            {
                arr[i] = oldarr[i];
            }
            delete[] oldarr;
        }

        arr[cs] = data;
        cs++;
    }

    void pop_back()
    {
        cs--;
    }

    int front() const
    {
        return arr[0];
    }

    int back() const
    {
        return arr[cs - 1];
    }

    bool empty() const
    {
        return cs == 0;
    }

    int size() const
    {
        return cs;
    }

    int capacity() const
    {
        return ms;
    }

    int operator[](const int i)
    { // we can use at in place of opertator
        return arr[i];
    }
};

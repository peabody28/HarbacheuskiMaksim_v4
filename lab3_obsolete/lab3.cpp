// number 4
#include <iostream>
#include <stdlib.h> 

class Page
{
private:
    int Number;
    int StrCount;

public:
    Page()
    {

    }

    int GetStrCount()
    {
        return StrCount;
    }

    friend class Book;
};

class Book
{
private:
    Page* Pages;
    int PagesCount;
    Page* Bookmark;

public:

    Book()
    {
        Pages = NULL;
    }

    Book(int count)
    {
        Pages = new Page[count];

        int numOfStr = rand() % 1000;
        for (int i = 0; i < count; i++)
        {
            Pages[i].StrCount = numOfStr;
            Pages[i].Number = i + 1;
        }
        
        PagesCount = count;
        Bookmark = Pages;
    }

    Book(Book& bk)
    {
        if (!bk.PagesCount)
        {
            Pages = NULL;
            return;
        }

        Pages = new Page[bk.PagesCount];
        PagesCount = bk.PagesCount;

        for(int i = 0; i < bk.PagesCount; i++)
            Pages[i] = bk.Pages[i];

        Bookmark = Pages + bk.Bookmark->Number-1;
    }

    ~Book()
    {
        delete[] Pages;
    }

    Page* OpenPage(int number)
    {
        return number <= PagesCount ? &Pages[number - 1] : NULL;
    }

    void PrintPageStrCount(int pageNumber)
    {
        std::cout << Pages[pageNumber - 1].GetStrCount() << std::endl;
    }

    void SetBookMark(int pageCount)
    {
        Bookmark = Pages + pageCount - 1;
    }

    int GetPagesCount()
    {
        return PagesCount;
    }

    void FindBookmark()
    {
        std::cout << Bookmark->Number << std::endl;
    }

    void* operator new(size_t size)
    {
        return malloc(size);
    }

    void operator delete(void* ptr)
    {
        Book* bk = (Book*)ptr;
        //free(bk->Pages); must be executed in destructor
        free(bk);
    }
};


int main()
{
    Book* bk = new Book(rand()%100);
    Book* bk2 = new Book(*bk);

    bk->SetBookMark(rand() % bk->GetPagesCount());

    bk->FindBookmark();
    bk2->FindBookmark();

    delete bk;
    delete bk2;

    std::cout << "Input books count" << std::endl;
    int booksCount;
    std::cin >> booksCount;

    Book* library = new Book[booksCount];
    for (int i = 0; i < booksCount; i++)
        library[i] = *(new Book(rand() % 1000));

    while (1)
    {
        std::cout << "Select book (number)" << std::endl;
        int bookNum;
        std::cin >> bookNum;
        if (bookNum == -1)
            break;
        Book bk = library[bookNum - 1];

        std::cout << "Select page number for opening" << std::endl;
        int pageNum;
        std::cin >> pageNum;
        Page* pg = bk.OpenPage(pageNum);

        std::cout << pg->GetStrCount() << std::endl;
    }

    delete[] library;

    return 0;
}
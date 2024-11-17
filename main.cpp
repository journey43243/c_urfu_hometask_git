
#include <iostream>
using namespace std;
struct book
{
    string isbn;
    int pages;
    string creator;
    string publisher;
    double rating;
};

string struct_func(int cnt, const book* arr[])
{
    setlocale(LC_ALL,"RU");
    int max_pages = 0;
    int max_indx;
    for (int i = 0; i<cnt; i++)
    {
        if (max_pages < (*arr)[i].pages)
        {
            max_pages = (*arr)[i].pages;
            max_indx = i;
        }
        else
        {
            continue;
        }
    }
    return (*arr)[max_indx].isbn;
};

int main(){
    book obj1;
    obj1.creator = "Л.Н.Толстой";
    obj1.isbn = "978-5-17-118103-1";
    obj1.pages = 1360;
    obj1.publisher = "АСТ";
    obj1.rating = 3.8;

    book obj2;
    obj2.creator = "Ф.М.Достоевский";
    obj2.isbn = "978-5-17-090630-7";
    obj2.pages = 672;
    obj2.publisher = "АСТ";
    obj2.rating = 4.2;

    book obj3;
    obj3.creator = "М.А.Шолохов";
    obj3.isbn = "978-5-389-16579-3";
    obj3.pages = 1328;
    obj3.publisher = "Азбука";
    obj3.rating = 4.1;

    book obj4;
    obj4.creator = "А.С.Пушкин";
    obj4.isbn = "978-5-389-16529-3";
    obj4.pages = 320;
    obj4.publisher = "Азбука";
    obj4.rating = 4.1;


    const book* strcs{new book[4] {obj1, obj2, obj3, obj4}};
    cout << struct_func(4, &strcs) << endl;
    delete [] strcs;
    strcs = nullptr;
}

/* copyright C++ Primer Plus */
#include <iostream>
#include <string>
struct free_throws {
    std::string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);
free_throws & clone(free_throws & ft);

int main()
{
    using namespace std;
    // 初始化参数
    free_throws one = {"one", 13, 14};
    free_throws two = {"two", 10, 16};
    free_throws three = {"three", 7, 9};
    free_throws four = {"four", 5, 9};
    free_throws five = {"five", 6, 14};
    free_throws team = {"team", 0, 0};

    free_throws dup;
    
    set_pc(one);
    display(one);
    accumulate(team, one);

    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    display(team);

    dup = accumulate(team, five);

    std::cout << "Display team:\n";
    display(team);

    std::cout << "Display dup after assignment:\n";
    display(dup);
    set_pc(four);

    accumulate(dup, five);
    std::cout << "Displaying dup after ill-advised assignment\n";
    display(dup);

    free_throws test;
    test = clone(dup);
    cout << "test addr:" << &test << endl;
    display(test);


    return 0;
}


free_throws & clone(free_throws & ft)
{
    using std::cout;
    free_throws *pt;
    cout << "pt addr:" << pt << std::endl;
    *pt = ft;
    cout << "pt addr:" << &(*pt) << std::endl;
    return *pt;
}

void display(const free_throws & ft)
{
    using std::cout;
    cout << "name:" << ft.name;
    cout << " made:" << ft.made;
    cout << " attempts:" << ft.attempts;
    cout << " percent:" << ft.percent << std::endl;
}

void set_pc(free_throws & ft)
{
    if (ft.attempts != 0) {
        ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
    } else {
        ft.percent = 0;
    }
}

free_throws & accumulate(free_throws & target, const free_throws & source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;
}
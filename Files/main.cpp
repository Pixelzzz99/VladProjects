#include <iostream>
#include "FirstVersion.hpp"
#include "SecondVersion.hpp"
#include "TaskGenerator.hpp"
#include <ctime>
#include <fstream>

TaskGenerator *task_global = new TaskGenerator(10);

int TestSimple1()
{
    FirstVersion *simple = new FirstVersion(task_global);
    std::cout << "WORD: " << task_global->getString() << std::endl;

    unsigned int time_start = clock();
    simple->solve();
    double time = (double)(clock() - time_start) / CLOCKS_PER_SEC;

    std::cout << "TIME: " << time << std::endl;
    delete simple;
    return 0;
}

int TestSimple2()
{
    SecondVersion *simple = new SecondVersion(task_global);
    std::cout << "WORD: " << task_global->getString() << std::endl;
    unsigned int time_start = clock();
    simple->solve();
    double time = (double)(clock() - time_start) / CLOCKS_PER_SEC;

    std::cout << "TIME: " << time << std::endl;
    delete simple;
    return 0;
}

int TestExcel()
{
    std::ofstream Table;
    Table.open("D:\\projects\\VladProjects\\Excel\\Table.csv");
    if (Table.is_open())
    {
        Table << "N ;"
              << "Time first ;"
              << "Time second ;" << std::endl;
        for (int i = 100; i <= 300; i += 20)
        {
            TaskGenerator *task_local = new TaskGenerator(i);
            std::cout << "i : " << i << std::endl;
            std::cout << "WORD: " << task_local->getString() << std::endl;
            FirstVersion *first = new FirstVersion(task_local);
            SecondVersion *second = new SecondVersion(task_local);
            unsigned int time_start = clock();
            first->solve();
            double timeFirst = (double)(clock() - time_start) / CLOCKS_PER_SEC;
            time_start = clock();
            second->solve();
            double timeSecond = (double)(clock() - time_start) / CLOCKS_PER_SEC;
            Table << i << ";" << timeFirst << ";" << timeSecond << std::endl;
            std::cout << "first time: " << timeFirst << std::endl;
            std::cout << "second time: " << timeSecond << std::endl;
            delete task_local;
            delete first;
            delete second;
        }
    }
    return 1;
}

int main()
{
    TestExcel();
    //    TestSimple1();
    //    TestSimple2();
    system("pause>nul");
    return 0;
}

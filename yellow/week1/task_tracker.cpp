#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Перечислимый тип для статуса задачи
//enum class TaskStatus {
//    NEW,          // новая
//    IN_PROGRESS,  // в разработке
//    TESTING,      // на тестировании
//    DONE          // завершена
//};
//
//// Объявляем тип-синоним для map<TaskStatus, int>,
//// позволяющего хранить количество задач каждого статуса
//using TasksInfo = map<TaskStatus, int>;


TaskStatus GetNextStatus(const TaskStatus &status) {
    switch (status) {
        case TaskStatus::NEW:
            return TaskStatus::IN_PROGRESS;
            break;
        case TaskStatus::IN_PROGRESS:
            return TaskStatus::TESTING;
            break;
        default:
            return TaskStatus::DONE;
            break;
    }
}

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo &GetPersonTasksInfo(const string &person) {
        return m[person];
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string &person) {
        if (m.count(person)) {
            m[person][TaskStatus::NEW] += 1;
        } else {
            m[person][TaskStatus::NEW] = 1;
        }
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string &person, int task_count) {
        TasksInfo updated;
        TasksInfo leftover;
        if (m.count(person)) {
            const map<string, TasksInfo> copy = m;

            for (const auto &[status, old_quantity] :copy.at(person)) {
                if (status == TaskStatus::DONE) break;

                if (task_count > 0) {
                    int new_quantity = max(0, old_quantity - task_count);
                    int diff = old_quantity - new_quantity;
                    task_count -= diff;


                    TaskStatus next_status = GetNextStatus(status);

                    m[person][status] -= diff;

                    if (m[person][status] == 0){
                        m[person].erase(status);
                    }

                    m[person][next_status] += diff;
                    updated[next_status] = diff;

                    if (new_quantity > 0) {
                        leftover[status] = new_quantity;
                    }
                } else {
                    leftover[status] = old_quantity;
                }
            }
        }
        return tie(updated, leftover);
    }

private:
    map<string, TasksInfo> m;

};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
    TeamTasks tasks;
    tasks.AddNewTask("Ivan");
    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask("Ivan");
    }

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 5);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);


    tie(updated_tasks, untouched_tasks) =
            tasks.PerformPersonTasks("Ivan", 5);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);


    return 0;
}



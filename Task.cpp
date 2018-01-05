//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
using namespace std;
//////////////////////////////////////////////////////////////
//
// local #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
#endif

//////////////////////////////////////////////////////////////
//
// struct definitions
//
#ifndef MARMOSET_TESTING

enum TaskType{LAUNDRY, DISHES, MAKE_BED, VACUUM, MOP_FLOOR, MOW_LAWN};

struct Task
{
    TaskType type; // Laundry, dishes, etc.
    int taskID;
    char* description;
};

struct TaskQueue
{
    Task* task;
    TaskQueue* nextInQueue;
};

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
//

bool enqueue(TaskQueue*& queue, const Task& task);
const Task* dequeue(TaskQueue*& queue);

//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS
//

bool enqueue(TaskQueue*& queue, const Task& task)
{
    
    if (task.description[0] == 0){
        return false;
    }
    
    
    if (queue->task == NULL){
        Task *temp = new Task;
        temp->type = task.type;
        temp->taskID = task.taskID;
        temp->description = task.description;
        queue->task = temp;
        return true;
    } else if (queue->task->taskID == task.taskID || queue->task->type == task.type) {
        return false;
    } else if (queue->nextInQueue == NULL){
        TaskQueue *q = new TaskQueue;
        Task *temp = new Task;
        temp->type = task.type;
        temp->taskID = task.taskID;
        temp->description = task.description;
        queue->nextInQueue = q; 
        q->task = temp;
        q->nextInQueue = NULL;
        return true;
    } else {
        TaskQueue *c = new TaskQueue;
        while (queue->nextInQueue!=NULL){
            c = queue->nextInQueue;
            enqueue(c, task);
        }
    } 
    
    return false;
}


const Task* dequeue(TaskQueue*& queue)
{
    if (queue->task == NULL){
        return 0;
    } else if (queue->nextInQueue == NULL){
        return queue->task;
    }
    
    TaskQueue *q = new TaskQueue;
    q = queue->nextInQueue;
    queue->nextInQueue = NULL;
    queue = q;
    return q->task;
    
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//
#ifndef MARMOSET_TESTING

int main(){
    // Some test driver code here ....
    cout << endl << "Implement some more appropriate tests in main()" << endl << endl;
    
    char sampleDescription[] = "sample description";
    
    TaskQueue* p_queue = new TaskQueue;
    p_queue->task = NULL;
    p_queue->nextInQueue = NULL;
    
    Task task1 =
    {
        .type = LAUNDRY,
        .taskID = 1,
        .description = sampleDescription
    };
    
    Task task2 =
    {
        .type = DISHES,
        .taskID = 2,
        .description = sampleDescription
    };
    
    Task task3 =
    {
        .type = MAKE_BED,
        .taskID = 3,
        .description = sampleDescription
    };
    
    bool enqueueSuccess = enqueue(p_queue, task1);
    if(enqueueSuccess)
        cout << "task1 enqueued successfully" << endl << endl;
    else
        cout << "enqueue() failed" << endl << endl;
    
    enqueueSuccess = enqueue(p_queue, task2);
    if(enqueueSuccess)
        cout << "task2 enqueued successfully" << endl << endl;
    else
        cout << "enqueue() failed" << endl << endl;
    
    enqueueSuccess = enqueue(p_queue, task3);
    if(enqueueSuccess)
        cout << "task3 enqueued successfully" << endl << endl;
    else
        cout << "enqueue() failed" << endl << endl;
    
    
    
    const Task* p_firstTaskInQueue = dequeue(p_queue);
    
    if (p_firstTaskInQueue)
    {
        cout << "Dequeue successful..." << endl;
        cout << "Type: " << p_firstTaskInQueue->type << endl;
        cout << "Task ID: " << p_firstTaskInQueue->taskID << endl;
        cout << "Description: " << p_firstTaskInQueue->description << endl;
    }
    else
        cout << "dequeue() failed" << endl;
    
    const Task* p_secondTaskInQueue = dequeue(p_queue);
    if (p_secondTaskInQueue)
    {
        cout << "Dequeue successful..." << endl;
        cout << "Type: " << p_secondTaskInQueue->type << endl;
        cout << "Task ID: " << p_secondTaskInQueue->taskID << endl;
        cout << "Description: " << p_secondTaskInQueue->description << endl;
    }
    else
        cout << "dequeue() failed" << endl;
    
    delete p_queue;
    
    return 0;
}
#endif



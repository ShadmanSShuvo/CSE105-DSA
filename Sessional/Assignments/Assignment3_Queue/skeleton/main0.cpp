#include <iostream>
#include <vector>
#include "queue.h"
using namespace std;

/********************************* RANDOM ************************************/
#define LCG_MULTIPLIER (1103515245)
#define LCG_INCREMENT (12345)
#define LCG_MODULUS ((unsigned)~0 >> 1)
static unsigned int lcg_seed = 1;
void custom_srand(unsigned int seed)
{
    lcg_seed = seed;
}
int custom_rand()
{
    lcg_seed = (LCG_MULTIPLIER * lcg_seed + LCG_INCREMENT) % (LCG_MODULUS + 1);
    return lcg_seed;
}
int randomQueue(int seed = -1)
{
    static bool initialized = false;
    if (seed != -1 && !initialized)
    {
        custom_srand(seed);
        initialized = true;
        return -1;
    }
    cout << "randomQueue() called" << endl;
    return (custom_rand() % 2) + 1;
}
/*****************************************************************************/

int main()
{
    freopen("test_input_1.txt", "r", stdin); // Test Case 1
    // freopen("test_input_2.txt", "r", stdin); // Test Case 2
    freopen("output.txt", "w", stdout);
    // Initialize the random generator with a fixed seed
    // You should set the seed only once at the beginning of your program
    // NOTE: Do not modify the following lines.
    randomQueue(42);

    Queue *Q1 = new ListQueue();
    Queue *Q2 = new ListQueue();
    Queue *Q = new ArrayQueue();

    int N;
    cin >> N;
    int time_stamp[10001] = {0}; // Array to store time stamps for each operation
    for (int i = 1; i <= N; i++)
    {
        // TODO: Edit here to add your own logic
        
        //cout << "Operation " << op_cnt << " (Arrival 101 1): randomQueue() called" << endl;
        int option;
        int time;
        int p_cnt = 0;
        cin >> option ;
         // Store the time stamp for this operation

        if(option == 1){ // arrival
            int id;
            cin >> id >> time;
            time_stamp[id] = time;
            p_cnt++;
            if(Q1->size() == 0 && Q2->size() == 0){
                //cout << "Enqueueing " << id << " to ArrayQueue" << endl;
                cout << "Operation " << i << " (Arrival "<< id <<" " << time << "): randomQueue() called" << endl;
                int rnd = randomQueue();
                if (rnd == 1)
                    Q1->enqueue(id);
                else
                    Q2->enqueue(id);
            }
            else if (Q1->size() == 0)
            {
                cout << "Operation " << i << " (Arrival "<< id <<" " << time << "): randomQueue() called" << endl;
                Q1->enqueue(id);
            }
            else if (Q2->size() == 0)
            {
                cout << "Operation " << i << " (Arrival "<< id <<" " << time << "): randomQueue() called" << endl;
                Q2->enqueue(id);
            }
            else{
                if(time_stamp[Q1->back()] << time_stamp[Q2->back()]){
                    cout << "Operation " << i << " (Arrival "<< id <<" " << time << "): randomQueue() called" << endl;
                    Q1->enqueue(id);
                }
                else{
                    cout << "Operation " << i << " (Arrival "<< id <<" " << time << "): randomQueue() called" << endl;
                    Q2->enqueue(id);
                }
            }
        }

        else if(option == 2) // leave
        {
            
        }

        else if (option == 5) // departure
        {
            if (Q1->size() > 0 && Q2->size() > 0)
            {
                
                int rnd = randomQueue();
                if (rnd == 1){
                    cout << "Operation " << i << " (Departure " << Q1->front() << "): randomQueue() called" << endl;
                    Q1->dequeue();
                }
                else{
                    cout << "Operation " << i << " (Departure " << Q2->front() << "): randomQueue() called" << endl;
                    Q2->dequeue();
                }
                
            }
            else if (Q1->size() > 0)
            {
                cout << "Operation " << i << " (Departure " << Q1->front() << "): randomQueue() called" << endl;
                Q1->dequeue();
            }
            else if (Q2->size() > 0)
            {
                cout << "Operation " << i << " (Departure " << Q2->front() << "): randomQueue() called" << endl;
                Q2->dequeue();
            }
        }
        else if (option == 3) // merge
        {
            cout << "Operation " << i << ": randomQueue() called" << endl;
            Q1->clear();
            Q2->clear();
        }
        {
            
        }


        // After each operation, we will check the queue's size and capacity
        // NOTE: Do not modify the following lines.
        int capacity = ((ArrayQueue *)Q)->getCapacity();
        if ((Q->size() < capacity / 4 && capacity > 2))
        {
            cout << "Error: Queue size is less than 25% of its capacity." << endl;
        }
        else if (capacity < 2)
        {
            cout << "Error: Queue capacity is less than 2." << endl;
        }
    }

    return 0;
}
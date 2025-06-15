#include <iostream>
#include <vector>
#include <algorithm>
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
    return (custom_rand() % 2) + 1;
}
/*****************************************************************************/

int main()
{
    freopen("test_input_1.txt", "r", stdin); // Test Case 1
    freopen("output1.txt", "w", stdout);
    // freopen("test_input_2.txt", "r", stdin); // Test Case 2
    // freopen("output2.txt", "w", stdout);

    // Initialize random generator with fixed seed
    // You should set the seed only once at the beginning of your program
    // NOTE: Do not modify the following lines.
    randomQueue(42);

    Queue *Q1 = new ListQueue();
    Queue *Q2 = new ListQueue();
    Queue *Q = new ArrayQueue();
    bool is_merged = false;

    int N;
    cin >> N;
    int time_stamp[10001] = {0}; // Array to store timestamps for each patient ID

    for (int i = 1; i <= N; i++)
    {
        // TODO: Edit here to add your own logic
        int option;
        cin >> option;

        if (option == 1) // Arrival
        {
            int id, time;
            cin >> id >> time;
            time_stamp[id] = time;
            cout << "Operation " << i << " (Arrival " << id << " " << time << "): ";
            if (!is_merged)
            {
                if (Q1->size() == 0 && Q2->size() == 0)
                {
                    cout << "randomQueue() called" << '\n';
                    int rnd = randomQueue();
                    if (rnd == 1)
                        Q1->enqueue(id);
                    else
                        Q2->enqueue(id);
                }
                else if (Q1->size() == 0)
                {
                    cout << '\n';
                    Q1->enqueue(id);
                }
                else if (Q2->size() == 0)
                {
                    cout << '\n';
                    Q2->enqueue(id);
                }
                else
                {
                    cout << '\n';
                    if (time_stamp[Q1->back()] <= time_stamp[Q2->back()])
                        Q1->enqueue(id);
                    else
                        Q2->enqueue(id);
                }
            }
            else
            {
                cout << '\n';
                Q->enqueue(id);
            }
        }
        else if (option == 2) // Leave
        {
            int id, time;
            cin >> id >> time;
            cout << "Operation " << i << " (Leave " << id << " " << time << "): " << '\n';

            if (!is_merged)
            {
                int size1 = Q1->size();
                for (int j = 0; j < size1; ++j)
                {
                    int front_id = Q1->front();
                    Q1->dequeue();
                    if (front_id != id)
                        Q1->enqueue(front_id);
                }

                int size2 = Q2->size();
                for (int j = 0; j < size2; ++j)
                {
                    int front_id = Q2->front();
                    Q2->dequeue();
                    if (front_id != id)
                        Q2->enqueue(front_id);
                }
            }
            else
            {
                int size = Q->size();
                for (int j = 0; j < size; ++j)
                {
                    int front_id = Q->front();
                    Q->dequeue();
                    if (front_id != id)
                        Q->enqueue(front_id);
                }
            }
        }
        else if (option == 3) // Merge
        {
            cout << "Operation " << i << " (Merge): " << '\n';
            if (!is_merged)
            {
                while(!Q1->empty() && !Q2->empty())
                {
                    int id1 = Q1->front();
                    int id2 = Q2->front();
                    if (time_stamp[id1] <= time_stamp[id2])
                    {
                        Q->enqueue(id1);
                        Q1->dequeue();
                    }
                    else
                    {
                        Q->enqueue(id2);
                        Q2->dequeue();
                    }
                }
                while (!Q1->empty())
                {
                    Q->enqueue(Q1->front());
                    Q1->dequeue();
                }
                while (!Q2->empty())
                {
                    Q->enqueue(Q2->front());
                    Q2->dequeue();
                }
                is_merged = true;
            }
        }
        else if (option == 4) // Split
        {
            cout << "Operation " << i << " (Split): " << '\n';
            if (is_merged)
            {
                int pos = 1;
                while (!Q->empty())
                {
                    int id = Q->front();
                    Q->dequeue();
                    if (pos % 2 == 1)
                        Q1->enqueue(id);
                    else
                        Q2->enqueue(id);
                    pos++;
                }
                is_merged = false;
            }
        }
        else if (option == 5) // Departure
        {
            cout << "Operation " << i << " (Departure";
            if (!is_merged)
            {
                if (Q1->size() > 0 && Q2->size() > 0)
                {
                    cout << "): randomQueue() called" << '\n';
                    int rnd = randomQueue();
                    if (rnd == 1)
                        Q1->dequeue();
                    else
                        Q2->dequeue();
                }
                else if (Q1->size() > 0 && Q2->size() == 0)
                {
                    cout << "): " << '\n';
                    Q1->dequeue();
                }
                else if (Q2->size() > 0 && Q1->size() == 0)
                {
                    cout << "): " << '\n';
                    Q2->dequeue();
                }
                else
                {
                    cout << "): " << '\n';
                }
            }
            else
            {
                if (Q->size() > 0)
                {
                    cout << "): " << '\n';
                    Q->dequeue();
                }
                else
                {
                    cout << "): " << '\n';
                }
            }
        }

        // Print queue states
        cout << "Q1: " << Q1->toString() << '\n';
        cout << "Q2: " << Q2->toString() << '\n';
        cout << "Q : " << Q->toString() << '\n';

        // Check ArrayQueue capacity
        int capacity = ((ArrayQueue *)Q)->getCapacity();
        if (Q->size() < capacity / 4 && capacity > 2)
        {
            cout << "Error: Queue size is less than 25% of its capacity." << '\n';
        }
        else if (capacity < 2)
        {
            cout << "Error: Queue capacity is less than 2." << '\n';
        }
    }

    delete Q1;
    delete Q2;
    delete Q;
    return 0;
}
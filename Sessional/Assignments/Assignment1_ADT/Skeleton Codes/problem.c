#include <stdio.h>
#include "arrayList.h"
// #include "linkedList.h"

int main()
{
    FILE* file = fopen("in_prob.txt", "r");
    if(file == NULL){
        return 1;
    }

    arrayList dal, fl;
    // linkedList dal, fl;
    
    // initialize the lists
    init(&dal);
    init(&fl);

    int func, param;
    while(fscanf(file, "%d", &func) == 1 && func != 0)
    {
        if(func == 1 && fscanf(file, "%d", &param) == 1){
            printf("Recruit %d\n", param);
            // implement logic here
            printf("DA List:\n");
            if(is_present(param, &fl)){
                printf("In the Foe list, cannot recruit\n\n");
                continue;
            }
            insert(param, &dal);
            if(size(&fl)>0){
                printf("Foe List:\n");
                print(&fl);
            }
            //print(&dal);
        }
        else if(func == 2 && fscanf(file, "%d", &param) == 1){
            printf("Fire %d\n", param);
            // implement logic here
            int temp = param;
            //delete_item(param, &dal);
            printf("DA List:\n");
            delete_item(param, &dal);
            printf("Foe List:\n");
            append(temp, &fl);
        }
        else if(func == 3 && fscanf(file, "%d", &param) == 1){
            printf("Check %d\n", param);
            //implement logic here
            int da = is_present(param, &dal);
            int foe = is_present(param, &fl);
            if(da)
                printf("Friend\n");
            else{
                if(foe)
                    printf("Foe\n");
                else
                    printf("Unknown\n");
            }

        }
        else{
            break;
        }
        printf("\n");
    }
   
    // free memory
    
    return 0;
}
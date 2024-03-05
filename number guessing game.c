#include<stdio.h>
#include<time.h>
#include<stdlib.h>


void populate_array (int *, int);
float average_array(int *, int);
int above_average_check (float, int);
void display_array(int *, int);

int main()
{
    int numbers, lives=3; //lives=number of attemtps to guess the number
    int x, guess, win_lose=0;
    int *arr;
    float avg;
    srand(time(NULL));

    printf("How many numbers would you like to generate?:");
    scanf("%d", &numbers);
    fflush(stdin);
    arr = (int*) malloc (sizeof(int*)*numbers);
    populate_array (arr, numbers);
    avg=average_array(arr, numbers);

    while(lives>0 && win_lose==0)
    {
        printf("\nGuess the average:");
        scanf("%d", &guess);
        fflush(stdin);
        win_lose=above_average_check (avg, guess);
        lives--;
    }
    display_array(arr, numbers);


    return 0;
}

void populate_array (int * arr, int numbers)
{
    int checker;
    for(checker=0; checker<numbers; checker++)
    {
        arr[checker]=50 + (int) rand() %51;
    }



}
float average_array(int * arr, int numbers)
{
    float average=0;
    int x;
    for(x=0; x<numbers; x++)
    {
        average=average + (arr[x]/numbers);
    }

    return average;


}
int above_average_check (float avg, int guess)
{

    if(guess==avg)
    {
        printf("\nYou win!");
        return 1;
    }
    else
    {
        if(guess>=avg-10 && guess<=avg+10)
        {
            printf("\nHOT!");
            printf("\nWrong guess, try again!");
        }
        else
        {
            printf("\nCOLD!");
            printf("\nWrong guess, try again!");
        }
        return 0;

    }
}

void display_array(int * arr, int numbers)
{
    int x;
    float avg;
    printf("\nGenerated %d numbers:", numbers);
    for(x=0; x<numbers; x++)
    {
        printf("%d ", arr[x]);
    }

    for(x=0; x<numbers; x++)
    {
        avg = avg + (arr[x]/numbers);
    }

    printf("\nAverage is: %.2f", avg);

}

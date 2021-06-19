#include "function.h"
#include <stdio.h>
#include <stdlib.h>

int compAscend(const void * a, const void * b){
    Grade gA = *(Grade *)a;
    Grade gB = *(Grade *)b;
    if(gA.total != gB.total)
        return gA.total - gB.total;
    else if(gA.Chinese != gB.Chinese)
        return gA.Chinese - gB.Chinese;
    else if(gA.English != gB.English)
        return gA.English - gB.English;
    else if(gA.math != gB.math)
        return gA.math - gB.math;
    else if (gA.science != gB.science)
        return gA.science - gB.science;
    else
        return gA.ID - gB.ID;
}

int compDescend(const void *a, const void *b)
{
    Grade gA = *(Grade *)a;
    Grade gB = *(Grade *)b;
    if (gB.total != gA.total)
        return gB.total - gA.total;
    else if (gB.Chinese != gA.Chinese)
        return gB.Chinese - gA.Chinese;
    else if (gB.English != gA.English)
        return gB.English - gA.English;
    else if (gB.math != gA.math)
        return gB.math - gA.math;
    else if (gB.science != gA.science)
        return gB.science - gA.science;
    else
        return gA.ID - gB.ID;
}

void sortGrade(Grade *gList, int n, char *order) {
    for(int i = 0; i < n; i++){
        gList[i].total = gList[i].Chinese + gList[i].English + gList[i].math + gList[i].science;
    }
    if (strncmp(order, "ascending", 9) == 0){
        qsort(gList, n, sizeof(Grade), compAscend);
    }
    else {
        qsort(gList, n, sizeof(Grade), compDescend);
    }
}

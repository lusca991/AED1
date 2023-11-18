#include <stdio.h>
#include "vetor.h"

void soma(vetor *v1, vetor *v2, vetor *result){
    result->x = v1->x + v2->x;
    result->y = v1->y + v2->y;
    result->z = v1->z + v2->z;

}
float produto_escalar(vetor *v1, vetor *v2){
    return v1->x * v2->x + v1 ->y * v2->y + v1->z * v2->z;   
}
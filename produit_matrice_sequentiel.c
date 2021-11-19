#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main()
{
    int A[50][50];
    int B[50][50];
    int C[50][50];
    int N, M, P;
    int I, J, K;
    long b = CLOCKS_PER_SEC;
    clock_t start, end;
    printf("*****matrice  de A****\n");
    printf("entre la valeur pour represente le  ligne de la matrice A (max.50) :");
    scanf("%d", &N);
    printf("entre la valeur pour represente le  colone de la matrice  A (max.50) :");
    scanf("%d", &M);
    for(I =0; I<N; I++)
        for(J=0; J<M; J++)
            {
            printf("entree la valeur pour donne la matrice [%d][%d] :",I,J);
            scanf("%d", &A[I][J]);
            }
    printf("******matrice de B***\n");
    printf("entre la valeur pour represente le  ligne de la matrice  B :%d\n", M);
    printf("entree la valeur pour represente le colone de la matrice  B (max.50) :");
    scanf("%d", &P);
    start = clock();
    for(I =0; I<M; I++)
        for(J=0; J<P; J++)
            {
            printf("entre la valeur pour donne la matrice[%d][%d] :",I,J);
            scanf("%d", &B[I][J]);
            }
    printf("les donnees de la matrice A:\n");
    for(I=0; I<N; I++)
        {
        for(J=0; J<M; J++)
            printf("%7d", A[I][J]);
        printf("\n");
        }
    printf("les donne de la matrice B:\n");
    for(I=0; I<M; I++)
        {
        for(J=0; J<P; J++)
            printf("%7d",B[I][J]);
        printf("\n");
        }
    for(I=0; I<N; I++)
        for(J=0; J<P; J++)
            {
            C[I][J] += A[I][K]*B[K][J];
            }
        end = clock();
    printf("temps comsommer est :%lf\n",
    (double)(end-start)/(double)b);
    printf("mresultat de multiplication de matrice A*B qui le  C:\n");
    for(I=0; I<N; I++)
        {
        for(J=0; J<P; J++)
            printf("%7d",C[I][J]);
        printf("\n");
        }
    return 0;
}

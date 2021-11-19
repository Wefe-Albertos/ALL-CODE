#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define ms 4
int main(int argc, char* argv[])
{
    int i,j,k;
    int x,c;
    int M_a[ms][ms];
    int M_b[ms][ms];
    int M_c[ms][ms];
    int rank, p;
    int NRPE;
    double starttime, endtime;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Status status;
    NRPE = ms / p;
    if(rank == 0)
    {
        printf("\n la valeur de la matrice de A:\n");
       

        for(i=0; i<ms; ++i)
            for(j=0; j<ms; ++j)
                M_a[i][j] =rand() % 10;
        for(i=0; i<ms; ++i)
        {
            for(j=0; j<ms; ++j)
                printf("%5d" , M_a[i][j]);
            printf("\n");
        }
        printf("\n la valeur de la matrice de  B:\n");
        
        for(x=0; x<ms; ++x)
            for(c=0; c<ms; ++c)
                M_b[x][c] = rand() % 10;
        for(x=0; x<ms; ++x)
        {
            for(c=0; c<ms; ++c)
                printf("%5d" , M_b[x][c]);
            printf("\n");
        }
    }
    for(i=0; i<ms; i++)
    {
        MPI_Bcast(M_b[i], ms*ms, MPI_INT, 0, MPI_COMM_WORLD);
    }
    printf("\n matrice B PAR LE PROCESUS: %d\n",rank);
    for(x=0; x<ms; ++x)
    {
        for(c=0; c<ms; ++c)
            printf("%5d",M_b[x][c]);
        printf("\n");
    }
    for(i=0; i<p; i++)
    {
        for(j=0; j<ms; j++)
        {
            MPI_Send(&M_a[j], ms*NRPE,MPI_INT,i,0,MPI_COMM_WORLD);
            NRPE++;
        }
    }
    MPI_Recv(M_a, ms*NRPE, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    //declaraton de fonction de time
    starttime = MPI_Wtime();
    for(k=0; k<ms; k++)
    for(i=0; i<ms; i++)
    	{
        M_c[i][k] = 0;
        for(j=0; j<ms; j++)
            M_c[i][k] = M_c[i][k] + M_a[i][j] * M_b[j][k];
        }
        endtime = MPI_Wtime();
    MPI_Send(&M_c[i][k], ms*ms, MPI_INT, 0, 0, MPI_COMM_WORLD);
    if(rank == 0)
    {
    //le resultat de deux matrice
        printf("\n le resutat de multiplication de matrice A*B qui donne  C:\n");
            for(i=0; i<ms; i++)
            {
            printf("\n");
            for(k=0; k<ms; k++)
                printf("%7d" , M_c[i][k]);
            }//temps global de traitement par le processus parallele
            printf("\n\n le temps paralisation est %f second\n", endtime-starttime);
    }
    printf("\n");
    return 0;
    MPI_Finalize();
}
//fait par albert wefe

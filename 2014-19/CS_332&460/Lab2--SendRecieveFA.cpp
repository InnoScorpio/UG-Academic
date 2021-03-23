#include "stdafx.h"
#include "mpi.h"
#include "stdio.h"
#include "iostream"
using namespace std;

int main(int argc, char *argv[])
{
	//char message[20] = "Hi there";
	int i, myrank;
	int nprogs = 3;
	int numtasks, rank, dest, source, rc, count, tag = 1;
	char message[20] = "Hi there";
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);


	/*if (myrank == 0) {
		// strcpy(message, "Hello, there)
		MPI_Send(message, strlen(message) + 1, MPI_CHAR, 1, 99, MPI_COMM_WORLD);
		cout << endl << "SP my rank: " << myrank << ", Sent: " << message << endl;
		// master process
	}
	else {
		// slave process
		for (int i = 1; i < 4; i++) {
			
			MPI_Recv(message, 20, MPI_CHAR, - 1, 99, MPI_COMM_WORLD, &status);
			cout << endl << "RP my rank: " << myrank << ", Received: " << message << endl;
		}
	}*/
	if (myrank = 0) // code for process zero
	{
		for (i = 1; i < nprogs; i++)
		{
			MPI_Send(&message, strlen(message), MPI_CHAR, i, 99, MPI_COMM_WORLD);
			//cout << endl << "SP my rank: " << myrank << ", Sent: " << message << endl;
			printf("Enter integer number ?\n"); scanf("%d", &message);
			system("pause");
		}
	}
		/*for (i = 1; i < nprogs; i++)
		{
			MPI_Recv(&message, 20, MPI_CHAR, i, 99, MPI_COMM_WORLD, &status);
			//cout << endl << "RP my rank: " << myrank << ", Received: " << incmessage << endl;
		}/**/
	
	else
	{
		for (i = 3; i > 0; i--)
		{
			MPI_Recv(&message, 20, MPI_CHAR, i, 99, MPI_COMM_WORLD, &status);
			printf("Received from slave %d: %d\n", i, message);
		}
		//cout << endl << "RP my rank: " << myrank << ", Received: " << message << endl;

		//	MPI_Send(&outmessage, strlen(outmessage), MPI_INT, 0, 99, MPI_COMM_WORLD);
		//rc = MPI_Recv(&inmessage, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
		
		
	}
	/*else if (myrank = 1)
		dest = 0;
		source = 0;
		rc = MPI_Recv(message, 20, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
		//rc = MPI_Send(&outmessage, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
		//cout << endl << "RP my rank: " << myrank << ", Received: " << incmessage << endl;
    
	rc = MPI_Get_count(&status, MPI_CHAR, &count);
	printf("Task %d: Received %d char(s) from task %d with tag %d \n",
		myrank, count, status.MPI_SOURCE, status.MPI_TAG);*/
	system("pause");
	MPI_Finalize();
	
}

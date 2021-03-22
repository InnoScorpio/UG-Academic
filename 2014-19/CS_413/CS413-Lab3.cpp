// CS413-MSMPI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mpi.h"

#include "stdio.h"

#include "iostream"

using namespace std;



int main(int argc, char *argv[])

{

	char message[20] = "Hi there";

	int myrank, mysize;
	int master = 0;
	MPI_Status status;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	//MPI_Comm_size(MPI_COMM_WORLD, &mysize);



	/*if (myrank == 0) {

	// strcpy(message, "Hello, there)

	MPI_Send(message, strlen(message) + 1, MPI_CHAR, 1, 99, MPI_COMM_WORLD);

	cout << endl << "SP my rank: " << myrank << ", Sent: " << message << endl;

	// master process

	}

	else {

	// slave process

	for (int i = 1; i < 3; i++) {



	MPI_Recv(message, 20, MPI_CHAR, - 1, 99, MPI_COMM_WORLD, &status);

	cout << endl << "RP my rank: " << myrank << ", Received: " << message << endl;

	}

	}*/

	if (myrank == 0) // code for process zero

	{



		for (int slave = 1; slave <= 3; slave++)

		{

			// strcpy(message, "Hello, there)

			MPI_Send(message, strlen(message) + 1, MPI_CHAR, slave, 99, MPI_COMM_WORLD);

			cout << endl << "SP my rank: " << myrank << ", Sent: " << message << " to rank " << slave << endl;

		}

	}

	else if (myrank == 1) // code for process one

	{

		//MPI_Send(message, strlen(message) + 1, MPI_CHAR, 2, 99, MPI_COMM_WORLD);

		MPI_Recv(message, 20, MPI_CHAR, master, 99, MPI_COMM_WORLD, &status);

		cout << endl << "RP my rank: " << myrank << ", Received: " << message << " from rank " << master << endl;

		//printf("received :%s:\n", message);

	}

	else if (myrank == 2) // code for process one

	{

		//MPI_Send(message, strlen(message) + 1, MPI_CHAR, 3, 99, MPI_COMM_WORLD);

		MPI_Recv(message, 20, MPI_CHAR, master, 99, MPI_COMM_WORLD, &status);

		cout << endl << "RP my rank: " << myrank << ", Received: " << message << " from rank " << master << endl;

		//printf("received :%s:\n", message);

	}

	else if (myrank == 3) // code for process one

	{

		//MPI_Send(message, strlen(message) + 1, MPI_CHAR, 1, 99, MPI_COMM_WORLD);

		MPI_Recv(message, 20, MPI_CHAR, master, 99, MPI_COMM_WORLD, &status);

		cout << endl << "RP my rank: " << myrank << ", Received: " << message << " from rank " << master << endl;

		//printf("received :%s:\n", message);

	}
	

	MPI_Finalize();

	system("pause");

}




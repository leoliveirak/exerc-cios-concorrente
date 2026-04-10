#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

//       (pai)      
//         |        
//    +----+----+
//    |         |   
// filho_1   filho_2


// ~~~ printfs  ~~~
// pai (ao criar filho): "Processo pai criou %d\n"
//    pai (ao terminar): "Processo pai finalizado!\n"
//  filhos (ao iniciar): "Processo filho %d criado\n"

// Obs:
// - pai deve esperar pelos filhos antes de terminar!

void childProcess() {
    printf("Processo filho criado %d\n", getpid());
    exit(0);
}

int main(int argc, char** argv) {

    // ....

    /*************************************************
     * Dicas:                                        *
     * 1. Leia as intruções antes do main().         *
     * 2. Faça os prints exatamente como solicitado. *
     * 3. Espere o término dos filhos                *
     *************************************************/

    #define FORK_ERROR -1
    #define CHILD 0

    for (int i = 0; i < 2; i++) {
        
        fflush(stdout);
        pid_t pid = fork();

        if (pid == FORK_ERROR) return 1;

        if (pid == CHILD) childProcess();
        
        printf("Processo pai criou %d\n", pid);
    }

    while(wait(NULL) >= 0);
    printf("Processo pai finalizado!\n");
    return 0;

}

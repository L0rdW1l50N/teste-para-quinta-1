#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//prototipo de fuções

void excluir(){
	setlocale(LC_ALL,"Portuguese");
	int escolha;
	printf("\n----------------------------------------------------------------------");
	printf("\n|||                                                                |||");
	printf("\n|||   Você Esta na Função de Excluir Funcionarios 2018.2           |||");
	printf("\n|||                                                                |||");
	printf("\n----------------------------------------------------------------------");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n Escolha o Tipo de Exclusão voce quer fazer !");
	printf("\n");
	printf("\n Suas escolhas são: ");
	printf("\n");
	printf("\n Digite 1 para O Sistema listarar todos os funcionários disponíveis \n e solicitar ao usuário o CPF do funcionário que ele deseja excluir;");
	printf("\n");
	printf("\n Digite 2 para O Sistema solicitara o nome do funcionário ao usuário \nque ele deseja excluir;");
	printf("\n");
	printf("\n Digite 3 para Voltar para o MENU;");
	printf("\n");
	printf("\n");
	scanf("%d",&escolha);
	if(escolha == 1){
		printf("\n vc escolheu 1");
	}else if(escolha == 2){
		printf("\n vc escolheu 2");
	}else if(escolha == 3){
		printf("\n vc escolheu Voltar para MENU");
		menu();
	}
}
void menu(){
	setlocale(LC_ALL,"Portuguese");
	int escolha;
	printf("\n----------------------------------------------------------------------");
	printf("\n|||                                                                |||");
	printf("\n|||   Seja Bem Vindo ao Gerenciamento de Funcionarios 2018.2       |||");
	printf("\n|||                                                                |||");
	printf("\n----------------------------------------------------------------------");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n Escolha o que voce quer fazer !");
	printf("\n Suas escolhas são: ");
	printf("\n Digite 1 para Incluir funcionario;");
	printf("\n Digite 2 para Alterar funcionario;");
	printf("\n Digite 3 para Excluir funcionario;");
	printf("\n Digite 4 para Procurar funcionario;");
	printf("\n Digite 5 para Sair do Programa;\n");
	printf("\n");
	scanf("%d",&escolha);
	if(escolha == 1){
		printf("\n vc escolheu Incluir");
	}else if(escolha == 2){
		printf("\n vc escolheu Alterar");
	}else if(escolha == 3){
		printf("\n vc escolheu Excluir");
		excluir();
	}else if(escolha == 4){
		printf("\n vc escolheu Procurar");
	}else if(escolha == 5){
		printf("\n vc escolheu Sair do Programa");
	}else if(escolha > 5){
		printf("\n Esta escolha não tem escolha novamente!");
		menu();
	}
	
}


int main(int argc, char *argv[]) {
	menu();
	return 0;
}

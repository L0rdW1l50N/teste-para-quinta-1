#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//prototipo de fuções
struct{
	char cpf[14];
	char nome[50];
	char telefone[11];
	char endereco[50];
	char ano_contrato[5];
}funcionario;
void incluir(){
	system("cls");
	char continuar;
	int escolha;
	FILE* arquivo;
	arquivo = fopen("dados.mdb", "ab");
	struct funcionario;
	
	if(arquivo == NULL){
		printf("Problemas ao abrir o arquivo!\n");
		getch();
	}
	else{
		
		setlocale(LC_ALL,"Portuguese");
		printf("\n----------------------------------------------------------------------");
		printf("\n|||                                                                |||");
		printf("\n|||   Você Esta na Função de Incluir Funcionarios 2018.2          |||");
		printf("\n|||                                                                |||");
		printf("\n----------------------------------------------------------------------");
		printf("\n");
		printf("\n");
		printf("\n");
		while(continuar != 'n'){
			printf("Informe os dados\n");
			fflush(stdin);
			
			printf("Informe o CPF:");
			fgets(funcionario.cpf, 14,stdin);
			fflush(stdin);
	
			printf("Informe o nome:");
			fgets(funcionario.nome, 50, stdin);
			fflush(stdin);
			
			printf("Informe o telefone:");
			fgets(funcionario.telefone, 11, stdin);
			fflush(stdin);
			
			printf("Informe o Endereço:");
			fgets(funcionario.endereco, 50, stdin);
			fflush(stdin);
			
			
			printf("Informe o ano de contratação:");
			fgets(funcionario.ano_contrato, 5, stdin);
			fflush(stdin);
			
			
			fwrite(&funcionario, sizeof(funcionario) , 1, arquivo);
			
			printf("Deseja inserir outro registro? (s/n)\n");
			scanf("%c", &continuar);
			
		};
		fclose(arquivo);
		printf("Deseja ir para menu digite 1 se deseja sair do Programa digite qualquer numero? \n");
		scanf("%d", &escolha);
		if(escolha == 1) menu();else if(escolha < 1) exit(0); else if(escolha > 1) exit(0);
	}
}
}


void buscar_cpf(){ //buscar via cpf
	
	system("cls");
	
	FILE* arquivo;
	
	struct funcionario;
	char cpf[14];
	int escolha;
	arquivo = fopen("dados.mdb", "rb");
	if(arquivo == NULL){
		puts("Problemas ao abrir o arquivo!\n");
	}
	else{
		printf("\n----------------------------------------------------------------------");
		printf("\n|||                                                                |||");
		printf("\n|||   Você Esta na Função de Procura Via CPF                       |||");
		printf("\n|||                                                                |||");
		printf("\n----------------------------------------------------------------------");
		printf("\n");
		printf("\n");
		printf("\n");
		fflush(stdin);
		printf("Digite o CPF a ser pesquisado\n");
		fflush(stdin);
		fgets(cpf, 14, stdin);			
		while(fread(&funcionario, sizeof(funcionario), 1, arquivo) == 1){
			if(strcmp(funcionario.cpf, cpf) == 0){
				printf("CPF: %s\n", funcionario.cpf);
				printf("Nome: %s\n", funcionario.nome);
				printf("Telefone: %s\n", funcionario.telefone);
				printf("Endereço: %s\n", funcionario.endereco);
				printf("Ano de contratação: %s\n", funcionario.ano_contrato);	
				printf("----------------------------------------------\n");	
				
			}
		}
	}
	getch();
	fclose(arquivo);
	printf("Deseja ir para menu digite 1 se deseja sair do Programa digite qualquer numero? \n");
	scanf("%d", &escolha);
	if(escolha == 1) menu();else if(escolha < 1) exit(0); else if(escolha > 1) exit(0);
}
void listar(){ //funcao de listar
	system("cls");
	FILE* arquivo;
	arquivo = fopen("dados.mdb", "rb");
	struct funcionario ;
	
	if(arquivo == NULL){
		puts("Problemas ao abrir o arquivo!\n");
	}
	else{
		char opc;
		printf("\n----------------------------------------------------------------------");
		printf("\n|||                                                                |||");
		printf("\n|||   Você Esta na Função de Procura de Funcionarios               |||");
		printf("\n|||                                                                |||");
		printf("\n----------------------------------------------------------------------");
		printf("\n");
		printf("\n");
		printf("\n");
			while(fread(&funcionario, sizeof(funcionario), 1, arquivo) == 1){
				printf("CPF: %s \n", funcionario.cpf);
				printf("Nome: %s \n", funcionario.nome);	
				printf("----------------------------------------------\n");
			}
				printf("Deseja vizualizar inforações completas? (s/n)");
				fflush(stdin);
				scanf("%c", &opc);
				if(opc == 's')
					buscar_cpf();
				else
				printf("Retornando ao menu principal...\n");
				menu();
		}
		fclose(arquivo);
		getch();
		
}
void pesquisaNome(){ // buscar via nome
	
	system("cls");
	FILE* arquivo;
	
	struct funcionario;
	char nome[50];
	int escolha;
	arquivo = fopen("dados.mdb", "rb");
	if(arquivo == NULL){
		puts("Problemas ao abrir o arquivo!\n");
	}
	else{
		printf("\n----------------------------------------------------------------------");
		printf("\n|||                                                                |||");
		printf("\n|||   Você Esta na Função de Procura Via Nome                      |||");
		printf("\n|||                                                                |||");
		printf("\n----------------------------------------------------------------------");
		printf("\n");
		printf("\n");
		printf("\n");
		fflush(stdin);
		printf("Digite o nome a ser pesquisado\n");
		fflush(stdin);
		fgets(nome, 50, stdin);	
		
		while(fread(&funcionario, sizeof(funcionario), 1, arquivo) == 1){
			if(strcmp(funcionario.nome,nome) == 0){
				printf("CPF: %s\n", funcionario.cpf);
				printf("Nome: %s\n", funcionario.nome);
				printf("Telefone: %s\n", funcionario.telefone);
				printf("Endereço: %s\n", funcionario.endereco);
				printf("Ano de contratação: %s\n", funcionario.ano_contrato);	
				printf("----------------------------------------------\n");	
				
			}
		}
	}
	
	fclose(arquivo);
	
	getch();
	printf("Deseja ir para menu digite 1 se deseja sair do Programa digite qualquer numero? \n");
	scanf("%d", &escolha);
	if(escolha == 1) menu();else if(escolha < 1) exit(0); else if(escolha > 1) exit(0);
}
void buscarSemelhante(){ // caçar pelo nome semelhante
	
	system("cls");
	
	FILE* arquivo;
	
	struct funcionario;
	char nome[5];
	char temp[5];
	int escolha;
	arquivo = fopen("dados.mdb", "rb");
	if(arquivo == NULL){
		puts("Problemas ao abrir o arquivo!\n");
	}
	else{
		cabecalho();
		printf("Digite os 2 primeiros digitos para pesquisar \n");
		fflush(stdin);
		fgets(nome, 5, stdin);	
		int x =0;
		while(fread(&funcionario, sizeof(funcionario), 1, arquivo) == 1){
			for(x; x < 5; x++){
				temp[x]= fscanf(arquivo,funcionario.nome);
			}
			if(strcmp(nome, temp) == 0){
				printf("CPF: %s\n", funcionario.cpf);
				printf("Nome: %s\n", funcionario.nome);
				printf("Telefone: %s\n", funcionario.telefone);
				printf("Endereço: %s\n", funcionario.endereco);
				printf("Ano de contratação: %s\n", funcionario.ano_contrato);	
				printf("----------------------------------------------\n");	
				
			}
		}
	}
	
	fclose(arquivo);
	getch();
	printf("Deseja ir para menu digite 1 se deseja sair do Programa digite qualquer numero? \n");
	scanf("%d", &escolha);
	if(escolha == 1) menu();else if(escolha < 1) exit(0); else if(escolha > 1) exit(0);
}


void alterar(){
	setlocale(LC_ALL,"Portuguese");
	int escolha;
	printf("\n----------------------------------------------------------------------");
	printf("\n|||                                                                |||");
	printf("\n|||   Você Esta na Função de Alterar Funcionarios 2018.2          |||");
	printf("\n|||                                                                |||");
	printf("\n----------------------------------------------------------------------");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n Escolha o que você quer fazer !");
	printf("\n");
	printf("\n Suas escolhas são: ");
	printf("\n");
	printf("\n Digite 1 para O Sistema Alterar as informações;");
	printf("\n");
	printf("\n Digite 2 para ir em função de excluir funcionário;");
	printf("\n");
	printf("\n Digite 3 para ir em função de procurar funcionário;");
	printf("\n");
	printf("\n Digite 4 para Voltar para o MENU;");
	printf("\n");
	printf("\n");
	scanf("%d",&escolha);
	if(escolha == 1){
		printf("\n vc escolheu para Alterar");
	}else if(escolha == 2){
		printf("\n vc escolheu para ir para Excluir");
		excluir();
	}else if(escolha == 3){
		printf("\n vc escolheu para ir para Procurar");
		procurar();
	}else if(escolha == 4){
		printf("\n vc escolheu para ir para o MENU");
		menu();
	}else if(escolha > 4){
		printf("\n vc escolheu errado escolha novamente");
		alterar();
		
	}
}

void procurar(){
setlocale(LC_ALL,"Portuguese");
	int escolha;
	printf("\n----------------------------------------------------------------------");
	printf("\n|||                                                                |||");
	printf("\n|||   Você Esta na Função de Procurar Funcionarios 2018.2          |||");
	printf("\n|||                                                                |||");
	printf("\n----------------------------------------------------------------------");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n Escolha o Tipo de Procura você quer fazer !");
	printf("\n");
	printf("\n Suas escolhas são: ");
	printf("\n");
	printf("\n Digite 1 para O Sistema solicitar o CPF ao usuário e apresentar \n todas as informações;");
	printf("\n");
	printf("\n Digite 2 para O Sistema  listarar todos os funcionários\n com CPF e nome e o usuário pode informar um CPF específico\n para visualizar todas as informações do funcionário;");
	printf("\n");
	printf("\n Digite 3 para O Sistema solicitar o nome do funcionário \n para o usuário. Com base o nome informado, o sistema deve\n apresentar todas as informações.;");
	printf("\n");
	printf("\n Digite 4 para O Sistema permiti a busca de funcionários \n com base em parte do nome exemplo: uma consulta por Ra deve \n apresentar Rafael, Ramom como resultados possíveis.;");
	printf("\n");
	printf("\n Digite 5 para Voltar para o MENU;");
	printf("\n");
	printf("\n");
	scanf("%d",&escolha);
	if(escolha == 1){
		printf("\n vc escolheu 1");
		buscar_cpf();
	}else if(escolha == 2){
		printf("\n vc escolheu 2");
		listar();
	}else if(escolha == 3){
		printf("\n vc escolheu 3");
		pesquisaNome();
		
	}else if(escolha == 4){
		printf("\n vc escolheu 4");
		buscarSemelhante();
		
	}else if(escolha == 5){
		printf("\n vc escolheu Voltar para MENU");
		menu();
	}else if(escolha > 5){
		printf("\n vc escolheu errado escolha novamente");
		procurar();
	}
}
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
	}else if(escolha == 3){
		printf("\n vc escolheu errado escolha novamente!");
		excluir();
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
		incluir();
	}else if(escolha == 2){
		printf("\n vc escolheu Alterar");
		alterar();
	}else if(escolha == 3){
		printf("\n vc escolheu Excluir");
		excluir();
	}else if(escolha == 4){
		printf("\n vc escolheu Procurar");
		procurar();
	}else if(escolha == 5){
		printf("\n vc escolheu Sair do Programa");
		exit(0);
	}else if(escolha > 5){
		printf("\n Esta escolha não tem escolha novamente!");
		menu();
	}
	
}


int main(int argc, char *argv[]) {
	menu();
	return 0;
}

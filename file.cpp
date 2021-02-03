#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>


//programa que lê notas de um arquivo, calcula sua média, e mostra o seu status.

int main(int argc, char *argv[]) {

	std::string nome, nota1, nota2, nota3, situacao;
	float media, quant_alunos = 3.0;

  	std::ifstream arquivo_entrada("notas.csv");
  	std::ofstream arquivo_saida("saida.csv", std::ios::app);

  	if(!arquivo_entrada.is_open()){

    std::cout << "Arquivo não existe ou não há permissão." << std::endl;

    return 1;
    
  	}

 	while(!arquivo_entrada.eof()){

 	std::getline(arquivo_entrada, nome, ';');
 	std::getline(arquivo_entrada, nota1, ';');
 	std::getline(arquivo_entrada, nota2, ';');
 	std::getline(arquivo_entrada, nota3);

 	// gravar nome
 	
 	media = (std::stof(nota1) + std::stof(nota2) + std::stof(nota3)) / quant_alunos;
 	//gravar media

 	if(media >= 7){

 		situacao = "Aprovado";
 	}
 	else{

 		situacao = "Reprovado";
 	}

 	//gravar situacao
 	std::cout << std::fixed << std::setprecision(1);
 	std::cout << nome << " " << media << " " << situacao << std::endl;
 	}
 	

	arquivo_entrada.close();
	arquivo_saida.close();

  	return 0;
}

#include <ctime>
#include <fstream>
#include <iostream>

std::string format_current_date(const std::string &format) {
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() { return format_current_date("# %d/%m/%Y "); }

std::string get_current_time() { return format_current_date("- %H:%M:%S "); }


int main(int argc, char const *argv[]){

  std::ofstream arquivo_saida("mensagem.md", std::ios::app);
  std::ifstream arquivo_entrada("mensagem.md");

  if(argc == 1){

    std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl; 
    std::cout << "Ou " << argv[0] << " list" << std::endl;

    return 1;
  }


  if(!arquivo_entrada.is_open()){

    std::cout << "Arquivo não existe ou não há permissão." << std::endl;

    return 1;
  }

  if(!arquivo_saida.is_open()){

   std::cout << "Arquivo não existe, ou não há permissão." << std::endl; 

    return 1;
  }

  std::string line;
  bool aux;

  while(!arquivo_entrada.eof()){

    std::getline(arquivo_entrada, line);

    if(line == get_current_date()){
      aux = true;
      break;
    }
    else{
      aux = false;
      break;
    }
  }

  std::string option; 
  option = argv[1];
  std::string mensagem;

  if(aux == true){

    if(option == "add"){

      if (argc == 2){
        std::cout << "Digite a mensagem: " << std::endl;
        std::getline(std::cin, mensagem);
        arquivo_saida << get_current_time() << mensagem << std::endl;
      }

      else{
        mensagem = argv[2];
        arquivo_saida << get_current_time() << mensagem << std::endl;
      }

      std::cout << "Mensagem adicionada :]" << std::endl;  
    } 
  }

  else{

    if(option == "add"){

      if (argc == 2){
        std::cout << "Digite a mensagem: " << std::endl;
        std::getline(std::cin, mensagem);
        arquivo_saida << get_current_date() << std::endl;
        arquivo_saida << get_current_time() << mensagem << std::endl;
      }

      else{
        mensagem = argv[2];
        arquivo_saida << get_current_date() << std::endl;
        arquivo_saida << get_current_time() << mensagem << std::endl;
      }
      std::cout << "Mensagem adicionada :]" << std::endl;  
    }
  }

  arquivo_saida.close();
  std::string linha;

  if(option == "list"){
  
    while(!arquivo_entrada.eof()){
      std::getline(arquivo_entrada, linha);

      if(linha[0] == '#'){
        continue;
      } 
      std::cout << linha << std::endl;
    }
  }

  arquivo_entrada.close();

  return 0;
}

#include <iostream>
#include <string>
#include <type_traits>
#include <variant>

/*

Polymorphism can be simulated in various ways. 
Implement the polymorphism with if, with switch,
 and with a dispatch table and compare the three implementations using static and dynamic polymorphism.

 */


// Write your code here
// After writing your code uncomment the lines in main

class MessageSeverity{
    public:
  const static std::string information;
  const static std::string warning;
  const static std::string fatal;
     
};

const std::string MessageSeverity::information="INFO";
const std::string MessageSeverity::warning="WARNING";
const std::string MessageSeverity::fatal="FATAL";

class MessInfo{
public:
    void show() const noexcept{
        std::cout << MessageSeverity::information<<"\n";
    }
};


class MessWarn{
public:
    void show() const noexcept{
        std::cout << MessageSeverity::warning<<"\n";
    }    
};

class MessFatal{
public:
    void show() const noexcept{
        std::cout << MessageSeverity::fatal<<"\n";
    }    
};

void writeMessage(const std::string str ){
    std::cout <<str<<"\n";
}



int main() {
  
  std::cout << std::endl;
  
  writeMessage(MessageSeverity::information);
  writeMessage(MessageSeverity::warning);
  writeMessage(MessageSeverity::fatal);
  
  using MesVariant=std::variant<MessInfo,MessFatal,MessWarn>;

  MesVariant mes=MessWarn();

 std::visit([](const auto& mes){mes.show();},mes);

 std::visit([](const auto& mes){
    using Type=std::remove_cv_t<std::decay_t<decltype(mes)>>;
    if constexpr (std::is_same_v<Type,MessWarn>){
        std::cout << "Warn Message\n";
    }
    if constexpr (std::is_same_v<Type,MessInfo>){
        std::cout << "Info Message\n";
    }
    if constexpr (std::is_same_v<Type,MessFatal>){
        std::cout << "Fatal Message\n";
    }
 },mes);

  std::cout << std::endl;
  
}
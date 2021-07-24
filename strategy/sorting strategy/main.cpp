//based on example in: https://refactoring.guru/design-patterns/strategy/cpp/example

#include "increase_sort.h"
#include "reverse_sort.h"
#include "context.h"

#include "increase_sort_functor.h"
#include "reverse_sort_functor.h"
#include "context_template.h"

#include <memory>
#include <functional>

void ClientCode()
{
    std::shared_ptr<Context> context = std::make_shared<Context>(new IncreaseSort);
    std::cout << "Client: Strategy is set to normal sorting.\n";
    context->doSomeBusinessLogic();
    std::cout << "\n";
    std::cout << "Client: Strategy is set to reverse sorting.\n";
    context->set_strategy(new ReverseSort);
    context->doSomeBusinessLogic();
}

void ClientCodeTemplate() 
{
    std::cout << "Client: Strategy is set to normal sorting.\n";
    ContextTemplate<IncreaseSortFunctor> contextA;
    contextA.doSomeBusinessLogic();
    std::cout << "\n";
    std::cout << "Client: Strategy is set to reverse sorting.\n";
    ContextTemplate<ReverseSortFunctor> contextB;
    contextB.doSomeBusinessLogic();
}

int main()
{
    std::cout<<"[main] Polymorphic Strategy:\n";
    ClientCode();

    std::cout<<"[main] Template Strategy:\n";
    ClientCodeTemplate();   

    return 0;
}
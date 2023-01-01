
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string_view>

bool debugMessage = false;

enum class Command
{
    None,
    Help,
    Quit,
    Compile,
};

enum class Argument
{
    None,
    Force,
};

std::unordered_map<std::string_view, Command> commandMap{
    {"help", Command::Help},
    {"q", Command::Quit},
    {"quit", Command::Quit},
    {"compile", Command::Compile},
};

std::unordered_map<std::string_view, Argument> argumentMap{
    {"!", Argument::Force},
};

Command parseCommand(std::string_view command)
{
    auto it = commandMap.find(command);
    if (it != commandMap.end())
    {
        return it->second;
    }
    return Command::None;
}

Argument parseArgument(std::string_view argument)
{
    auto it = argumentMap.find(argument);
    if (it != argumentMap.end())
    {
        return it->second;
    }
    return Argument::None;
}

void executeCommand(Command command, Argument argument, std::string_view data)
{
    switch (command)
    {

    case Command::Quit:
        if (argument == Argument::Force)
        {
            std::cout << "\033[1;34mBye!\033[0m" << std::endl;
            exit(0);
        }
        else
        {
            std::cout << "\033[1;31mAre you sure you want to quit? You will be unable to use the compiler until you re-run the binary.\033[0m" << std::endl;
            std::cout << "[Y/N] ";
            std::string confirm;
            std::getline(std::cin, confirm);
            if (confirm == "Y" || confirm == "y")
            {
                std::cout << "\033[1;34mBye!\033[0m" << std::endl;
                exit(0);
            }
            else
            {
                std::cout << "Operation cancelled." << std::endl;
            }
        }
        break;
    case Command::Help:
        std::cout << "ko [command] <arguments>" << std::endl;
        std::cout << "Available commands:" << std::endl;
        std::cout << "  h, help      Show this help message" << std::endl;
        std::cout << "  q, quit      Quit the compiler" << std::endl;
        std::cout << "  c, compile   Compile a file" << std::endl;
        break;
    case Command::Compile:
    {
        std::cout << "Begining compilation..." << data << std::endl;
        bool success = false;
        if (success)
        {
            std::cout << "Secsessfully compiled" << data << std::endl;
            data = "";
            debugMessage = true;
        }
        else
        {
            std::cout << "Compilation failed..." << std::endl;
            std::cout << debugMessage << std::endl;
            data = "";
            debugMessage = true;
        }
    }
    break;
    case Command::None:
    {
        if (argument == Argument::None)
        {
            std::cout << "ko [command] <arguments>" << std::endl;
            std::cout << "Available commands:" << std::endl;
            std::cout << "  h, help      Show this help message" << std::endl;
            std::cout << "  q, quit      Quit the compiler" << std::endl;
            std::cout << "  c, compile   Compile a file" << std::endl;
        }
        else
        {
            std::cout << "Error: Invalid command" << std::endl;
        }
    }
    break;
    }
}

int main()
{
    while (true)
    {
        std::cout << "ko> ";
        std::string line;
        std::getline(std::cin, line);

        std::vector<std::string_view> tokens;
        std::size_t start = 0;
        std::size_t end = line.find(' ');
        while (end != std::string::npos)
        {
            tokens.push_back(line.substr(start, end - start));
            start = end + 1;
            end = line.find(' ', start);
        }
        tokens.push_back(line.substr(start));

        if (tokens.empty())
        {
            continue;
        }

        if (tokens[0] != "ko")
        {
            std::cout << "Invalid command. Type 'ko help' for a list of available commands." << std::endl;
            continue;
        }

        if (tokens.size() == 1)
        {
            executeCommand(Command::Help, Argument::None, "");
            continue;
        }

        Command command = parseCommand(tokens[1]);
        Argument argument = Argument::None;
        std::string_view data = "";
        if (tokens.size() >= 3)
        {
            argument = parseArgument(tokens[2]);
            data = tokens[2];
        }
        if (tokens.size() >= 4)
        {
            data = tokens[3];
        }

        executeCommand(command, argument, data);
    }

    return 0;
}

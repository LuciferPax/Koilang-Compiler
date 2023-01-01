#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <string>

int main()
{
  std::cout << "Do you want to install Koxx? [Y/N] ";
  char response;
  std::cin >> response;
  if (response == 'Y' || response == 'y')
  {
    std::cout << "Installation in progress..." << std::endl;
    int numFiles = 20;

    // folder creation
    system("md C:\\Koxx");
    system("md C:\\Koxx\\bin");
    system("md C:\\Koxx\\lib");
    system("md C:\\Koxx\\interactions");
    system("md C:\\Koxx\\lib\\koilang");
    system("md C:\\Koxx\\lib\\koilang\\1.0.0");
    system("md C:\\Koxx\\lib\\koilang\\1.0.0\\make");
    system("md C:\\Koxx\\lib\\koilang\\1.0.0\\make\\debug");

    // file creation
    std::ofstream cliFile("C:\\Koxx\\interactions\\cli.cpp");
    std::ofstream handlerFile("C:\\Koxx\\lib\\koilang\\1.0.0\\make\\debug\\handler.cpp");
    std::ofstream stdinFile("C:\\Koxx\\lib\\stdin.cpp");
    std::ofstream stdlibFile("C:\\Koxx\\lib\\stdlib.cpp");
    std::ofstream koilang_coreFile("C:\\Koxx\\lib\\koilang\\1.0.0\\make\\koilang_core.cpp");
    std::ofstream vruntimeFile("C:\\Koxx\\lib\\koilang\\1.0.0\\make\\vruntime.cpp");

    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < numFiles; i++)
    {
      int progress = (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count()) / 10 * numFiles;
      // Stop the progress bar at 100%
      if (progress > 100)
      {
        progress = 100;
      }
      char color;
      if (progress < 33)
        color = '4';
      else if (progress < 66)
        color = '6';
      else
        color = '2';
      std::string progressBar = "\x1B[" + std::string(1, color) + "m[";
      for (int j = 0; j < 50; j++)
      {
        if (j < progress / 2)
          progressBar += "=";
        else
          progressBar += " ";
      }
      progressBar += "] " + std::to_string(progress) + "%\x1B[0m";
      std::cout << "\r" << progressBar << std::flush;
      std::system("ping -n 2 localhost > nul");
    }
    // Print "Done!" when the installation is complete
    std::cout << std::endl
              << "Done!" << std::endl;
  }
  return 0;
}

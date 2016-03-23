cmake_minimum_required(VERSION 3.4)
project(source)

find_package(GSL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    DataManaging/Test/TestReader/TestReader.cpp
    DataManaging/Test/TestReader/TestReader.hpp
    DataManaging/Test/TestWriter/main.cpp
    DataManaging/Test/TestWriter/TestWriter.cpp
    DataManaging/Test/TestWriter/TestWriter.hpp
    DataManaging/DataManager.cpp
    DataManaging/DataManager.hpp
    DataManaging/FileDataReader.cpp
    DataManaging/FileDataReader.hpp
    DataManaging/FileDataWriter.cpp
    DataManaging/FileDataWriter.hpp
    DataManaging/InputDataManager.cpp
    DataManaging/InputDataManager.hpp
    information/InformationStrategy/BivariateStrategy.cpp
    information/InformationStrategy/BivariateStrategy.hpp
    information/InformationStrategy/InformationStrategy.hpp
    information/InformationStrategy/TrivariateStrategy.cpp
    information/InformationStrategy/TrivariateStrategy.hpp
    "information/Mutual Information/BiInformationCalculator.cpp"
    "information/Mutual Information/BiInformationCalculator.hpp"
    information/ResultTable/BiResultTableRow.cpp
    information/ResultTable/BiResultTableRow.hpp
    information/ResultTable/ResultTable.cpp
    information/ResultTable/ResultTable.hpp
    information/ResultTable/ResultTableRow.cpp
    information/ResultTable/ResultTableRow.hpp
    information/ResultTable/TriResultTableRow.cpp
    information/ResultTable/TriResultTableRow.hpp
    information/RootFinder/RootFinder.cpp
    information/RootFinder/RootFinder.hpp
    "information/Transmission Matrix/MatrixCalculator.cpp"
    "information/Transmission Matrix/MatrixCalculator.hpp"
    Main/main.cpp
    Main/MainMenu.cpp
    Main/MainMenu.hpp)

add_executable(source ${SOURCE_FILES})
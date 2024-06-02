#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

void copyHiddenFiles(const fs::path& sourceDir, const fs::path& destDir) {
    try {
        if (!fs::exists(sourceDir)) {
            throw std::runtime_error("Source directory does not exist.");
        }
        if (!fs::exists(destDir)) {
            fs::create_directories(destDir);
        }

        for (const auto& entry : fs::recursive_directory_iterator(sourceDir)) {
            if (entry.is_regular_file() && entry.path().filename().string().front() == '.') {
                std::string destFileName = sourceDir.filename().string() + "_" + entry.path().filename().string();
                fs::path destFilePath = destDir / destFileName;

                std::ifstream src(entry.path(), std::ios::binary);
                std::ofstream dst(destFilePath, std::ios::binary);

                dst << src.rdbuf();

                std::cout << "Copied hidden file: " << entry.path() << " to " << destFilePath << std::endl;
            }
        }
    }
    catch (const fs::filesystem_error& ex) {
        std::cerr << "Filesystem error: " << ex.what() << std::endl;
    }
    catch (const std::runtime_error& ex) {
        std::cerr << "Runtime error: " << ex.what() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "An error occurred: " << ex.what() << std::endl;
    }
}

int main() {
    std::string sourceDirPath;
    std::string destDirPath;

    std::cout << "Enter the source directory path: ";
    std::getline(std::cin, sourceDirPath);
    std::cout << "Enter the destination directory path: ";
    std::getline(std::cin, destDirPath);

    fs::path sourceDir(sourceDirPath);
    fs::path destDir(destDirPath);

    copyHiddenFiles(sourceDir, destDir);

    return 0;
}

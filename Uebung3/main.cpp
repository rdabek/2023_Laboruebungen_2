#include <fstream>
#include <filesystem>
#include <vector>
#include <optional>
#include <iostream>
#include <cmath>

auto readDateFromFile(const std::filesystem::path& path) -> std::optional<std::vector<std::tuple<double, double>>> {
    std::ifstream dataFile(path);
    if(!dataFile) {
        std::nullopt;
    }
    std::vector<std::tuple<double, double>> ret;
    std::string line{};
    while(std::getline(dataFile, line)) {
        double m{}, s{};
        std::istringstream lineStream(line);
        lineStream >> s >> m;
        ret.push_back({s, m});
    }
    return ret;
}

auto readDateFromFile2(const std::filesystem::path& path) -> std::optional<std::vector<double>> {
    std::ifstream dataFile(path);
    if(!dataFile) {
        std::nullopt;
    }
    std::vector<double> ret;
    std::string line{};
    while(std::getline(dataFile, line)) {
        double m{};
        std::istringstream lineStream(line);
        lineStream >> m;
        ret.push_back(m);
    }
    return ret;
}

auto main() -> int {
    std::cout << "Interferometrie:" << std::endl;
    // Messung 1:
    std::cout << std::endl << "Messung1: " << std::endl;
    auto messung1Data = readDateFromFile("../Uebung3/versuch1.dat");
    if(!messung1Data)
        return 0;
    double mdls = 0.0;
    double msigma = 0.0;
    int count=0;
    for(const auto& data : messung1Data.value()) {
        double lambda = 633;
        double s = std::get<0>(data);
        double m = std::get<1>(data);
        double dls = m*lambda/(2*s);
        double sigmai = std::sqrt(std::pow(lambda/(2*s), 2)+std::pow(m*lambda/(2*s*s)*0.5*0.5, 2));
        std::cout << "s: " << s << ", m: " << m << ", dls: " << dls << ", sigma i: " << sigmai << std::endl;
        mdls += dls;
        msigma += std::pow(sigmai, 2);
        count++;
    }
    msigma = std::sqrt(msigma)/count;
    mdls /= count;
    std::cout << "Mittelwert dls: " << mdls << ", Standardabweichung: " << msigma << std::endl << std::endl;

    //Messung 3:
    std::cout << std::endl << "Messung3: " << std::endl;
    auto messung3Data = readDateFromFile("../Uebung3/versuch3.dat");
    if(!messung3Data)
        return 0;
    double mlambda = 0.0;
    msigma = 0.0;
    count=0;
    for(const auto& data : messung3Data.value()) {
        double s = std::get<0>(data);
        double m = std::get<1>(data);
        double lambda = 2*s*mdls/m;
        double sigmai = std::sqrt(std::pow(lambda/(2*s), 2)+std::pow(m*lambda/(2*s*s)*0.5*0.5, 2));
        std::cout << "s: " << s << ", m: " << m << ", lambda: " << lambda << ", sigma i: " << sigmai << std::endl;
        mlambda += lambda;
        msigma += std::pow(sigmai, 2);
        count++;
    }
    msigma = std::sqrt(msigma)/count;
    mlambda /= count;
    std::cout << "Mittelwert lambda: " << mlambda << ", Standardabweichung: " << msigma << std::endl;
    double lambda3 = mlambda;

    //Messung 4:
    std::cout << std::endl << "Messung4: " << std::endl;
    auto messung4Data = readDateFromFile2("../Uebung3/versuch4.dat");
    if(!messung4Data)
        return 0;
    msigma = 0.0;
    count=0;
    for(const auto& m : messung4Data.value()) {
        double kl = m*0.02;
        double sigmai = 0.1;
        std::cout << "m: " << m << ", kl: " << kl << ", sigmai: " << sigmai << std::endl;
        msigma += std::pow(sigmai, 2);
        count++;
    }
    msigma = std::sqrt(msigma)/(count);
    std::cout << "Standardabweichung: " << msigma << std::endl;

    //Messung 5:
    std::cout << std::endl << "Messung5: " << std::endl;
    auto messung5Data = readDateFromFile2("../Uebung3/versuch5.dat");
    if(!messung5Data)
        return 0;
    for(const auto& s : messung5Data.value()) {
        double dlambda = std::pow(lambda3, 2)/(20000*s);
        std::cout << "dlambda: " << dlambda << std::endl;
    }

    return 0;
}
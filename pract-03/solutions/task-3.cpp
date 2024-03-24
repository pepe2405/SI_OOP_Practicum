#include <iostream>
#include <fstream>

constexpr size_t MAX_NAME_LENGTH = 26;
constexpr char FILE_PATH[] = "offers.dat";

struct Offer {
    char companyName[MAX_NAME_LENGTH];
    size_t devsInTeam;
    size_t annualPaidLeave;
    size_t salary;
};

constexpr Offer ERROR_OFFER = {"ERROR", 0, 0, 0};

void readOffer(Offer &offer) {
    std::cin >> offer.companyName >> offer.devsInTeam
             >> offer.annualPaidLeave >> offer.salary;

}

void printOffer(const Offer &offer) {
    std::cout << offer.companyName << " " << offer.devsInTeam << " "
              << offer.annualPaidLeave << " " << offer.salary << std::endl;
}

Offer *readOffers(size_t n) {
    Offer *jobOffers = new Offer[n];

    for (size_t i = 0; i < n; i++) {
        readOffer(jobOffers[i]);
    }

    return jobOffers;
}

void saveOffers(const char *filePath, const Offer *offers, size_t offersCount) {
    if (!filePath) {
        std::cout << "No file path" << std::endl;
        return;
    }

    if (!offers) {
        std::cout << "No offers" << std::endl;
        return;
    }

    std::ofstream file(filePath, std::ios::binary | std::ios::app);
    if (!file.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return;
    }

    file.write((const char *) offers, offersCount * sizeof(Offer));
    file.close();
}

size_t getFileSize(std::ifstream &file) {
    size_t currentPos = file.tellg();

    file.seekg(0, std::ios::end);
    size_t size = file.tellg();

    file.seekg(currentPos);
    return size;
}


Offer *readOffers(const char *filePath, size_t &offersCount) {
    if (!filePath) {
        std::cout << "No file path" << std::endl;
        return nullptr;
    }

    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return nullptr;
    }

    size_t fileSize = getFileSize(file);
    offersCount = fileSize / sizeof(Offer);
    Offer *offers = new Offer[offersCount];

    file.read((char *) offers, fileSize);
    file.close();

    return offers;
}

void filterOffers(const char *filePath, size_t minSalary) {
    size_t offersCount = 0;
    Offer *offers = readOffers(filePath, offersCount);

    for (size_t i = 0; i < offersCount; ++i) {
        if (offers[i].salary >= minSalary) {
            printOffer(offers[i]);
        }
    }

    delete[] offers;
}

Offer findOffer(const char *filePath, const char *companyName) {
    if (!companyName) {
        std::cout << "No company name" << std::endl;
        return ERROR_OFFER;
    }

    size_t offersCount = 0;
    Offer *offers = readOffers(filePath, offersCount);

    for (size_t i = 0; i < offersCount; ++i) {
        if (strcmp(offers[i].companyName, companyName) == 0) {
            Offer offer = offers[i];
            delete[] offers;
            return offer;
        }
    }

    delete[] offers;
    return ERROR_OFFER;
}

int main() {
    size_t n;
    std::cin >> n;

    Offer *offers = readOffers(n);
    saveOffers(FILE_PATH, offers, n);

    delete[] offers;

    size_t minSalary;
    std::cin >> minSalary;

    filterOffers(FILE_PATH, minSalary);

    char companyName[MAX_NAME_LENGTH];
    std::cin >> companyName;

    Offer offer = findOffer(FILE_PATH, companyName);
    printOffer(offer);

    return 0;
}
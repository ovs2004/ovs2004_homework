#include <iostream>
void XML(int id,double weight, bool broken, double price) {

    std::printf("\t<MobilePhone id=\"%i\" weight=\"%.1f\" is_broken=\"%s\" price=\"%.6g\"/>\n", id, weight, (broken) ? "true":"false", price);

}
struct MobileTel {
    int id;
    double weight;
    bool is_broken;
    double price;
};

int main() {
    int count_tel;
    std::cin >> count_tel;
    MobileTel phone[count_tel];
    for (int i = 0; i < count_tel; ++i) {
        std::cin >> phone[i].weight >> phone[i].is_broken >> phone[i].price;

    }
    std::cout << "<MobilePhones>\n";
    for (int i = 0; i < count_tel; i++) {
        XML(i, phone[i].weight, phone[i].is_broken, phone[i].price);
    }
    std::cout << "</MobilePhones>\n";
    return 0;
}


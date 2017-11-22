#include <iostream>
#include <string>
#include <tuple>

#include "hand.pb.h"

void populateHandEvent(atheer::HandEvent& event) {
    auto hand = event.add_hands();

    for (int i = 0; i < 5; ++i) {
        auto finger = hand->add_fingers();
        finger->set_id(i);
        finger->mutable_tip()->set_x(1.0 * i);
        finger->mutable_tip()->set_y(2.0 * i);
        finger->mutable_tip()->set_z(3.0 * i);
    }
}

void printHandEvent(const atheer::HandEvent& event) {
    auto hands = event.hands();
    for (int i = 0; i < hands.size(); ++i) {
        std::cout << "hand #" << i << std::endl;
        auto fingers = hands[i].fingers();
        for (int j = 0; j < fingers.size(); ++j) {
            // clang-format off
            std::cout <<
            "Finger id " << fingers[j].id() <<
            " fingertip.x: " << fingers[j].tip().x() <<
            " fingertip.y: " << fingers[j].tip().y() <<
            " fingertip.z: " << fingers[j].tip().z() << std::endl;
            // clang-format on
        }
    }
}

int main(int argc, char const* argv[]) {
    // 1. make hand event and serialize it
    atheer::HandEvent event_out;
    populateHandEvent(event_out);
    std::string bufferStr;
    auto success = event_out.SerializeToString(&bufferStr);
    std::cout << "Serialized string: " << bufferStr << std::endl;

    // 2. now deserialize the buffer to get the hand event back
    atheer::HandEvent event_in;
    event_in.ParseFromArray((void*)bufferStr.data(), bufferStr.size());
    printHandEvent(event_in);

    return 0;
}
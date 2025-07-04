add_library(vending_machine_sk_lib
        chicago/vending_machine.cpp
        chicago/vending_machine.h
        chicago/item.cpp
        chicago/item.h
        chicago/order.h
        chicago/Inventory.cpp
        chicago/Inventory.h
        chicago/OrderStrategy.cpp
        chicago/OrderStrategy.h

        london/vending_machine.cpp
        london/vending_machine.h
        london/item.cpp
        london/item.h
        london/order.h
        london/Inventory.cpp
        london/Inventory.h
        london/OrderStrategy.cpp
        london/OrderStrategy.h
        chicago/OrderService.cpp
        chicago/OrderService.h

)
target_include_directories(vending_machine_sk_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

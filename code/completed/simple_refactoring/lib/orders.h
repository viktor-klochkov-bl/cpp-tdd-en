// Copyright (c) 2025 Dr. Matthias Hölzl. All rights reserved.

// ReSharper disable CppDFAConstantFunctionResult
#pragma once
#ifndef SIMPLE_REFACTORING_LIB_LIBRARY_H
#define SIMPLE_REFACTORING_LIB_LIBRARY_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace simpleRefactoring
{
    // Examples of code that needs refactoring

    struct OrderLine
    {
        std::string product;
        int quantity;
        double price;
    };

    // Encapsulated company name
    class CompanyInfo
    {
        static std::string name;

    public:
        [[nodiscard]] static std::string GetName()
        {
            return name;
        }
        static void SetName(const char* newName)
        {
            name = newName;
        }
    };

    // Helper function to create sample data
    inline std::vector<OrderLine> MakeOrderLines()
    {
        return {{"Laptop", 2, 999.99}, {"Mouse", 5, 25.50}, {"Keyboard", 3, 75.00}};
    }

    // Example 1: Functions after Extract Function refactoring
    inline void PrintReceiptHeader()
    {
        std::cout << "=== " << CompanyInfo::GetName() << " Invoice ===\n";
        std::cout << std::left << std::setw(12) << "Product" << " " << std::right
                  << std::setw(8) << "Quantity" << " " << std::setw(10) << "Price" << " "
                  << std::setw(12) << "Subtotal" << "\n";
        std::cout << std::string(50, '-') << "\n";
    }

    inline void PrintOrderLines(const std::vector<OrderLine>& orderLines)
    {
        for (const auto& orderLine : orderLines)
        {
            double subtotal = orderLine.quantity * orderLine.price;
            std::cout << std::left << std::setw(12) << orderLine.product << " "
                      << std::right << std::setw(8) << orderLine.quantity << " "
                      << std::fixed << std::setprecision(2) << std::setw(10)
                      << orderLine.price << "€ " << std::setw(11) << subtotal << "€\n";
        }
        std::cout << std::string(50, '-') << "\n";
    }

    inline double CalculateSubtotal(const std::vector<OrderLine>& orderLines)
    {
        double total = 0.0;
        for (const auto& orderLine : orderLines)
        {
            total += orderLine.quantity * orderLine.price;
        }
        return total;
    }

    [[nodiscard]] inline double ApplyDiscount(double total)
    {
        double discountAmount = total * 0.1; // 10% discount
        total = total - discountAmount;
        std::cout << "Discount (10%): -" << std::fixed << std::setprecision(2)
                  << discountAmount << "€\n";
        return total;
    }

    inline void PrintReceiptFooter(double total)
    {
        std::cout << "Total: " << std::fixed << std::setprecision(2) << total << "€\n";
        std::cout << "Thank you for your business!\n\n";
    }

    inline void PrintReceipt(const std::vector<OrderLine>& orderLines, bool applyDiscount)
    {
        PrintReceiptHeader();
        PrintOrderLines(orderLines);

        double total = CalculateSubtotal(orderLines);
        if (applyDiscount)
        {
            total = ApplyDiscount(total);
        }

        PrintReceiptFooter(total);
    }

    // Example 2: Applied Change Function Signature refactoring
    inline double CalculateTotalWithoutDiscountAndTax(
        const std::vector<OrderLine>& orderLines, double taxRate, bool applyDiscount)
    {
        double t = 0.0;
        for (const auto& line : orderLines)
        {
            t += line.quantity * line.price;
        }
        if (applyDiscount)
        {
            t *= 0.9; // 10% discount
        }
        t += t * taxRate; // Add tax
        return t;
    }

    // Example 3: Function that could benefit from Extract Variable
    inline double CalculateShipping(const std::vector<OrderLine>& orderLines,
                                    const std::string& destination)
    {
        double weight = 0.0;
        for (const auto& line : orderLines)
        {
            constexpr auto itemWeight = 0.5;
            weight += line.quantity * itemWeight;
        }

        // Complex shipping calculation that could use explanatory variables
        if (destination == "domestic")
        {
            constexpr auto heavyShippingThreshold = 5.0;
            constexpr auto baseShipping = 5.99;
            constexpr auto weightMultiplier = 1.2;
            constexpr auto heavyBaseShipping = 2.5;

            return (weight < heavyShippingThreshold)
                ? baseShipping
                : (weight * weightMultiplier + heavyBaseShipping);
        }
        else if (destination == "europe")
        {
            constexpr auto heavyShippingThreshold = 2.0;
            constexpr auto baseShipping = 15.99;
            constexpr auto weightMultiplier = 2.8;
            constexpr auto heavyBaseShipping = 8.0;
            return (weight < heavyShippingThreshold)
                ? baseShipping
                : (weight * weightMultiplier + heavyBaseShipping);
        }
        else
        {
            // international
            constexpr auto heavyShippingThreshold = 1.0;
            constexpr auto baseShipping = 25.99;
            constexpr auto weightMultiplier = 4.5;
            constexpr auto heavyBaseShipping = 15.0;
            return (weight < heavyShippingThreshold)
                ? baseShipping
                : (weight * weightMultiplier + heavyBaseShipping);
        }
    }

    // Example 4: Unnecessary variable that could be inlined
    inline double GetOrderLineValue(const OrderLine& orderLine)
    {
        return orderLine.quantity * orderLine.price;
    }

    // Example 5: Class with exposed data that needs encapsulation

    // Example 6: Function that could be inlined (too simple)
    inline double GetTaxRate()
    {
        return 0.19; // 19% VAT
    }

    class Customer
    {
        std::string name;
        std::string email;
        int loyaltyPoints{};

    public:
        [[nodiscard]] std::string GetName() const
        {
            return name;
        }
        void SetName(std::string name)
        {
            this->name = std::move(name);
        }
        [[nodiscard]] std::string GetEmail() const
        {
            return email;
        }
        void SetEmail(std::string email)
        {
            this->email = std::move(email);
        }
        [[nodiscard]] int LoyaltyPoints() const
        {
            return loyaltyPoints;
        }
        [[nodiscard]] int& LoyaltyPoints()
        {
            return loyaltyPoints;
        }

        void display() const
        {
            std::cout << "Customer: " << name << " (" << email << ")\n";
            std::cout << "Loyalty Points: " << loyaltyPoints << "\n";
        }
    };

    inline double CalculateTotalWithTax(double subtotal)
    {
        return subtotal + (subtotal * GetTaxRate());
    }

} // namespace simpleRefactoring

#endif // SIMPLE_REFACTORING_LIB_LIBRARY_H

#pragma once

#include <array>
#include <cstddef>
#include <iterator>

// ============================================================
// A fixed-capacity ring buffer with a hand-written iterator.
// Entirely in this header — templates can't be split into .h/.cpp
// with implicit instantiation (same reason as Day 10's factories).
// ============================================================
template <typename T, std::size_t Capacity>
class RingBuffer {
public:
    void push(const T& value) {
        data_[(start_ + count_) % Capacity] = value;
        if (count_ < Capacity) {
            ++count_;
        } else {
            start_ = (start_ + 1) % Capacity; // buffer full: overwrite oldest
        }
    }

    std::size_t size() const noexcept { return count_; }

    // ============================================================
    // Custom forward iterator
    // ============================================================
    // Why the STL cares about iterator CATEGORIES: algorithms like
    // std::distance or std::advance behave completely differently
    // depending on what an iterator can do. A RandomAccessIterator
    // lets std::distance compute (last - first) in O(1). A plain
    // ForwardIterator (this one) forces std::distance to walk the
    // whole range one ++ at a time — O(n). The category tag below is
    // how the STL knows which strategy is even legal to use.
    class Iterator {
    public:
        // These five typedefs are what make this a real "iterator"
        // to the STL — algorithms look them up via
        // std::iterator_traits<Iterator>. Miss one and std::distance,
        // std::advance, and range-based STL algorithms won't compile
        // against this type at all.
        using iterator_category = std::forward_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = const T*;
        using reference         = const T&;

        Iterator(const RingBuffer* buf, std::size_t index)
            : buf_(buf), index_(index) {}

        reference operator*() const {
            return buf_->data_[(buf_->start_ + index_) % Capacity];
        }
        pointer operator->() const { return &(**this); }

        Iterator& operator++() {
            ++index_;
            return *this;
        }
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const Iterator& other) const {
            return buf_ == other.buf_ && index_ == other.index_;
        }
        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

    private:
        const RingBuffer* buf_;
        std::size_t index_;
    };

    Iterator begin() const { return Iterator(this, 0); }
    Iterator end()   const { return Iterator(this, count_); }

private:
    std::array<T, Capacity> data_{};
    std::size_t start_ = 0;
    std::size_t count_ = 0;
};

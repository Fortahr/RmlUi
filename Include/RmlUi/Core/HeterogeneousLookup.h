#pragma once

#include "../Config/Config.h"
#include "StringView.h"

namespace Rml
{
    struct RmlRobinHash
    {
        using is_transparent = void;

        size_t operator()(const String& str) const
        {
            return robin_hood::hash_bytes(str.data(), str.size());
        }

        size_t operator()(const char* str) const noexcept
        {
            return robin_hood::hash_bytes(str, std::strlen(str));
        }

        size_t operator()(const StringView& str) const noexcept
        {
            return robin_hood::hash_bytes(str.data(), str.size());
        }

        size_t operator()(size_t hash) const noexcept
        {
            return hash;
        }

        template<typename T>
        static constexpr size_t ct_hash(const T& str)
        {
            return RmlRobinHash()(str);
        }
    };

    struct RmlRobinEqual
    {
        using is_transparent = void;

        bool operator()(const char* lhs, const std::string& rhs) const noexcept
        {
            return std::strcmp(lhs, rhs.c_str()) == 0;
        }

        bool operator()(const std::string& lhs, const std::string& rhs) const
        {
            return lhs == rhs;
        }

        bool operator()(const StringView& lhs, const std::string& rhs) const noexcept
        {
            return lhs == rhs;
        }
    };
}
/*
Bibliography:
https://en.cppreference.com/w/cpp/types/integer
https://gcc.gnu.org/onlinedocs/cpp/Predefined-Macros.html
https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html
https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html
In folder "Bibliography:
Fixed width integer types (since C++11) - cppreference.com
Standard Predefined Macros (The C Preprocessor)
Common Predefined Macros (The C Preprocessor)
*/

#include <iostream>
#include <cfloat>

using std::cout;

int main()
{
    cout << "Predefined macros in C++\n";
    cout << "1. Standard macros\n";
    cout << "__FILE__: ";
    #ifdef __FILE__
        cout << __FILE__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__LINE__: ";
    #ifdef __LINE__
        cout << __LINE__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__DATE__: ";
    #ifdef __DATE__
        cout << __DATE__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__TIME__: ";
    #ifdef __TIME__
        cout << __TIME__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__cplusplus: ";
    #ifdef __cplusplus
        cout << __cplusplus;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__STDC__: ";
    #ifdef __STDC__
        cout << __STDC__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__STDC_HOSTED__: ";
    #ifdef __STDC_HOSTED__
        cout << __STDC_HOSTED__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__STDC_VERSION__: ";
    #ifdef __STDC_VERSION__
        cout << __STDC_VERSION__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__OBJC__: ";
    #ifdef __OBJC__
        cout << __OBJC__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__ASSEMBLER__: ";
    #ifdef __ASSEMBLER__
        cout << __ASSEMBLER__;
    #else
        cout << "undefined";
    #endif
    cout << "\n" << "\n";


    cout << "2. Common macros\n";
    cout << "__COUNTER__: ";
    #ifdef __COUNTER__
        cout << __COUNTER__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GFORTRAN__: ";
    #ifdef __GFORTRAN__
        cout << __GFORTRAN__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GNUC__: ";
    #ifdef __GNUC__
        cout << __GNUC__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GNUC_MINOR__: ";
    #ifdef __GNUC_MINOR__
        cout << __GNUC_MINOR__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GNUC_PATCHLEVEL__: ";
    #ifdef __GNUC_PATCHLEVEL__
        cout << __GNUC_PATCHLEVEL__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GNUG__: ";
    #ifdef __GNUG__
        cout << __GNUG__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__STRICT_ANSI__: ";
    #ifdef __STRICT_ANSI__
        cout << __STRICT_ANSI__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__BASE_FILE__: ";
    #ifdef __BASE_FILE__
        cout << __BASE_FILE__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__FILE_NAME__: ";
    #ifdef __FILE_NAME__
        cout << __FILE_NAME__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INCLUDE_LEVEL__: ";
    #ifdef __INCLUDE_LEVEL__
        cout << __INCLUDE_LEVEL__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__ELF__: ";
    #ifdef __ELF__
        cout << __ELF__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__VERSION__: ";
    #ifdef __VERSION__
        cout << __VERSION__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__OPTIMIZE__: ";
    #ifdef __OPTIMIZE__
        cout << __OPTIMIZE__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__OPTIMIZE_SIZE__: ";
    #ifdef __OPTIMIZE_SIZE__
        cout << __OPTIMIZE_SIZE__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__NO_INLINE__: ";
    #ifdef __NO_INLINE__
        cout << __NO_INLINE__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GNUC_GNU_INLINE__: ";
    #ifdef __GNUC_GNU_INLINE__
        cout << __GNUC_GNU_INLINE__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GNUC_STDC_INLINE__: ";
    #ifdef __GNUC_STDC_INLINE__
        cout << __GNUC_STDC_INLINE__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__CHAR_UNSIGNED__: ";
    #ifdef __CHAR_UNSIGNED__
        cout << __CHAR_UNSIGNED__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__WCHAR_UNSIGNED__: ";
    #ifdef __WCHAR_UNSIGNED__
        cout << __WCHAR_UNSIGNED__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__REGISTER_PREFIX__: ";
//    #ifdef __REGISTER_PREFIX__
//        cout << __REGISTER_PREFIX__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__USER_LABEL_PREFIX__: ";
//    #ifdef __USER_LABEL_PREFIX__
//        cout << __USER_LABEL_PREFIX__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__SIZE_TYPE__: ";
//    #ifdef __SIZE_TYPE__
//        cout << __SIZE_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__PTRDIFF_TYPE__: ";
//    #ifdef __PTRDIFF_TYPE__
//        cout << __PTRDIFF_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__WCHAR_TYPE__: ";
//    #ifdef __WCHAR_TYPE__
//        cout << __WCHAR_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INTMAX_TYPE__: ";
//    #ifdef __INTMAX_TYPE__
//        cout << __INTMAX_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINTMAX_TYPE__: ";
//    #ifdef __UINTMAX_TYPE__
//        cout << __UINTMAX_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__SIG_ATOMIC_TYPE__: ";
//    #ifdef __SIG_ATOMIC_TYPE__
//        cout << __SIG_ATOMIC_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INT8_TYPE__: ";
//    #ifdef __INT8_TYPE__
//        cout << __INT8_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INT16_TYPE__: ";
//    #ifdef __INT16_TYPE__
//        cout << __INT16_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INT32_TYPE__: ";
//    #ifdef __INT32_TYPE__
//        cout << __INT32_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INT64_TYPE__: ";
//    #ifdef __INT64_TYPE__
//        cout << __INT64_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINT8_TYPE__: ";
//    #ifdef __UINT8_TYPE__
//        cout << __UINT8_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINT16_TYPE__: ";
//    #ifdef __UINT16_TYPE__
//        cout << __UINT16_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINT32_TYPE__: ";
//    #ifdef __UINT32_TYPE__
//        cout << __UINT32_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINT64_TYPE__: ";
//    #ifdef __UINT64_TYPE__
//        cout << __UINT64_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INT_LEAST8_TYPE__: ";
//    #ifdef __INT_LEAST8_TYPE__
//        cout << __INT_LEAST8_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INT_LEAST16_TYPE__: ";
//    #ifdef __INT_LEAST16_TYPE__
//        cout << __INT_LEAST16_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INT_LEAST32_TYPE__: ";
//    #ifdef __INT_LEAST32_TYPE__
//        cout << __INT_LEAST32_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INT_LEAST64_TYPE__: ";
//    #ifdef __INT_LEAST64_TYPE__
//        cout << __INT_LEAST64_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINT_LEAST8_TYPE__: ";
//    #ifdef __UINT_LEAST8_TYPE__
//        cout << __UINT_LEAST8_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINT_LEAST16_TYPE__: ";
//    #ifdef __UINT_LEAST16_TYPE__
//        cout << __UINT_LEAST16_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINT_LEAST32_TYPE__: ";
//    #ifdef __UINT_LEAST32_TYPE__
//        cout << __UINT_LEAST32_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INT_FAST8_TYPE__: ";
//    #ifdef __INT_FAST8_TYPE__
//        cout << __INT_FAST8_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INT_FAST16_TYPE__: ";
//    #ifdef __INT_FAST16_TYPE__
//        cout << __INT_FAST16_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INT_FAST32_TYPE__: ";
//    #ifdef __INT_FAST32_TYPE__
//        cout << __INT_FAST32_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INT_FAST64_TYPE__: ";
//    #ifdef __INT_FAST64_TYPE__
//        cout << __INT_FAST64_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINT_FAST8_TYPE__: ";
//    #ifdef __UINT_FAST8_TYPE__
//        cout << __UINT_FAST8_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINT_FAST16_TYPE__: ";
//    #ifdef __UINT_FAST16_TYPE__
//        cout << __UINT_FAST16_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINT_FAST32_TYPE__: ";
//    #ifdef __UINT_FAST32_TYPE__
//        cout << __UINT_FAST32_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINT_FAST64_TYPE__: ";
//    #ifdef __UINT_FAST64_TYPE__
//        cout << __UINT_FAST64_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INTPTR_TYPE__: ";
//    #ifdef __INTPTR_TYPE__
//        cout << __INTPTR_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINTPTR_TYPE__: ";
//    #ifdef __UINTPTR_TYPE__
//        cout << __UINTPTR_TYPE__;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__CHAR_BIT__: ";
    #ifdef __CHAR_BIT__
        cout << __CHAR_BIT__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SCHAR_MAX__: ";
    #ifdef __SCHAR_MAX__
        cout << __SCHAR_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__WCHAR_MAX__: ";
    #ifdef __WCHAR_MAX__
        cout << __WCHAR_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SHRT_MAX__: ";
    #ifdef __SHRT_MAX__
        cout << __SHRT_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_MAX__: ";
    #ifdef __INT_MAX__
        cout << __INT_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__LONG_MAX__: ";
    #ifdef __LONG_MAX__
        cout << __LONG_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__LONG_LONG_MAX__: ";
    #ifdef __LONG_LONG_MAX__
        cout << __LONG_LONG_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__WINT_MAX__: ";
    #ifdef __WINT_MAX__
        cout << __WINT_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIZE_MAX__: ";
    #ifdef __SIZE_MAX__
        cout << __SIZE_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__PTRDIFF_MAX__: ";
    #ifdef __PTRDIFF_MAX__
        cout << __PTRDIFF_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INTMAX_MAX__: ";
    #ifdef __INTMAX_MAX__
        cout << __INTMAX_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__UINTMAX_MAX__: ";
    #ifdef __UINTMAX_MAX__
        cout << __UINTMAX_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIG_ATOMIC_MAX__: ";
    #ifdef __SIG_ATOMIC_MAX__
        cout << __SIG_ATOMIC_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT8_MAX__: ";
    #ifdef __INT8_MAX__
        cout << __INT8_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT16_MAX__: ";
    #ifdef __INT16_MAX__
        cout << __INT16_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT32_MAX__: ";
    #ifdef __INT32_MAX__
        cout << __INT32_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT64_MAX__: ";
    #ifdef __INT64_MAX__
        cout << __INT64_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__UINT8_MAX__: ";
    #ifdef __UINT8_MAX__
        cout << __UINT8_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__UINT16_MAX__: ";
    #ifdef __UINT16_MAX__
        cout << __UINT16_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__UINT32_MAX__: ";
    #ifdef __UINT32_MAX__
        cout << __UINT32_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__UINT64_MAX__: ";
    #ifdef __UINT64_MAX__
        cout << __UINT64_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_LEAST8_MAX__: ";
    #ifdef __INT_LEAST8_MAX__
        cout << __INT_LEAST8_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_LEAST16_MAX__: ";
    #ifdef __INT_LEAST16_MAX__
        cout << __INT_LEAST16_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_LEAST32_MAX__: ";
    #ifdef __INT_LEAST32_MAX__
        cout << __INT_LEAST32_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_LEAST64_MAX__: ";
    #ifdef __INT_LEAST64_MAX__
        cout << __INT_LEAST64_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__UINT_LEAST8_MAX__: ";
    #ifdef __UINT_LEAST8_MAX__
        cout << __UINT_LEAST8_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__UINT_LEAST16_MAX__: ";
    #ifdef __UINT_LEAST16_MAX__
        cout << __UINT_LEAST16_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__UINT_LEAST32_MAX__: ";
    #ifdef __UINT_LEAST32_MAX__
        cout << __UINT_LEAST32_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__UINT_LEAST64_MAX__: ";
    #ifdef __UINT_LEAST64_MAX__
        cout << __UINT_LEAST64_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_FAST8_MAX__: ";
    #ifdef __INT_FAST8_MAX__
        cout << __INT_FAST8_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_FAST16_MAX__: ";
    #ifdef __INT_FAST16_MAX__
        cout << __INT_FAST16_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_FAST32_MAX__: ";
    #ifdef __INT_FAST32_MAX__
        cout << __INT_FAST32_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_FAST64_MAX__: ";
    #ifdef __INT_FAST64_MAX__
        cout << __INT_FAST64_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__UINT_FAST8_MAX__: ";
    #ifdef __UINT_FAST8_MAX__
        cout << __UINT_FAST8_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__UINT_FAST16_MAX__: ";
    #ifdef __UINT_FAST16_MAX__
        cout << __UINT_FAST16_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__UINT_FAST32_MAX__: ";
    #ifdef __UINT_FAST32_MAX__
        cout << __UINT_FAST32_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__UINT_FAST64_MAX__: ";
    #ifdef __UINT_FAST64_MAX__
        cout << __UINT_FAST64_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INTPTR_MAX__: ";
    #ifdef __INTPTR_MAX__
        cout << __INTPTR_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__UINTPTR_MAX__: ";
    #ifdef __UINTPTR_MAX__
        cout << __UINTPTR_MAX__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__WCHAR_MIN__: ";
    #ifdef __WCHAR_MIN__
        cout << __WCHAR_MIN__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__WINT_MIN__: ";
    #ifdef __WINT_MIN__
        cout << __WINT_MIN__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIG_ATOMIC_MIN__: ";
    #ifdef __SIG_ATOMIC_MIN__
        cout << __SIG_ATOMIC_MIN__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT8_C: ";
//    #ifdef __INT8_C
//        cout << __INT8_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INT16_C: ";
//    #ifdef __INT16_C
//        cout << __INT16_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INT32_C: ";
//    #ifdef __INT32_C
//        cout << __INT32_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INT64_C: ";
//    #ifdef __INT64_C
//        cout << __INT64_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINT8_C: ";
//    #ifdef __UINT8_C
//        cout << __UINT8_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINT16_C: ";
//    #ifdef __UINT16_C
//        cout << __UINT16_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINT32_C: ";
//    #ifdef __UINT32_C
//        cout << __UINT32_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINT64_C: ";
//    #ifdef __UINT64_C
//        cout << __UINT64_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__INTMAX_C: ";
//    #ifdef __INTMAX_C
//        cout << __INTMAX_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__UINTMAX_C: ";
//    #ifdef __UINTMAX_C
//        cout << __UINTMAX_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "__SCHAR_WIDTH__: ";
    #ifdef __SCHAR_WIDTH__
        cout << __SCHAR_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SHRT_WIDTH__: ";
    #ifdef __SHRT_WIDTH__
        cout << __SHRT_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_WIDTH__: ";
    #ifdef __INT_WIDTH__
        cout << __INT_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__LONG_WIDTH__: ";
    #ifdef __LONG_WIDTH__
        cout << __LONG_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__LONG_LONG_WIDTH__: ";
    #ifdef __LONG_LONG_WIDTH__
        cout << __LONG_LONG_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__PTRDIFF_WIDTH__: ";
    #ifdef __PTRDIFF_WIDTH__
        cout << __PTRDIFF_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIG_ATOMIC_WIDTH__: ";
    #ifdef __SIG_ATOMIC_WIDTH__
        cout << __SIG_ATOMIC_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIZE_WIDTH__: ";
    #ifdef __SIZE_WIDTH__
        cout << __SIZE_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__WCHAR_WIDTH__: ";
    #ifdef __WCHAR_WIDTH__
        cout << __WCHAR_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__WINT_WIDTH__: ";
    #ifdef __WINT_WIDTH__
        cout << __WINT_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_LEAST8_WIDTH__: ";
    #ifdef __INT_LEAST8_WIDTH__
        cout << __INT_LEAST8_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_LEAST16_WIDTH__: ";
    #ifdef __INT_LEAST16_WIDTH__
        cout << __INT_LEAST16_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_LEAST32_WIDTH__: ";
    #ifdef __INT_LEAST32_WIDTH__
        cout << __INT_LEAST32_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_LEAST64_WIDTH__: ";
    #ifdef __INT_LEAST64_WIDTH__
        cout << __INT_LEAST64_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_FAST8_WIDTH__: ";
    #ifdef __INT_FAST8_WIDTH__
        cout << __INT_FAST8_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_FAST16_WIDTH__: ";
    #ifdef __INT_FAST16_WIDTH__
        cout << __INT_FAST16_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_FAST32_WIDTH__: ";
    #ifdef __INT_FAST32_WIDTH__
        cout << __INT_FAST32_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INT_FAST64_WIDTH__: ";
    #ifdef __INT_FAST64_WIDTH__
        cout << __INT_FAST64_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INTPTR_WIDTH__: ";
    #ifdef __INTPTR_WIDTH__
        cout << __INTPTR_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__INTMAX_WIDTH__: ";
    #ifdef __INTMAX_WIDTH__
        cout << __INTMAX_WIDTH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIZEOF_INT__: ";
    #ifdef __SIZEOF_INT__
        cout << __SIZEOF_INT__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIZEOF_LONG__: ";
    #ifdef __SIZEOF_LONG__
        cout << __SIZEOF_LONG__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIZEOF_LONG_LONG__: ";
    #ifdef __SIZEOF_LONG_LONG__
        cout << __SIZEOF_LONG_LONG__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIZEOF_SHORT__: ";
    #ifdef __SIZEOF_SHORT__
        cout << __SIZEOF_SHORT__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIZEOF_POINTER__: ";
    #ifdef __SIZEOF_POINTER__
        cout << __SIZEOF_POINTER__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIZEOF_FLOAT__: ";
    #ifdef __SIZEOF_FLOAT__
        cout << __SIZEOF_FLOAT__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIZEOF_DOUBLE__: ";
    #ifdef __SIZEOF_DOUBLE__
        cout << __SIZEOF_DOUBLE__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIZEOF_LONG_DOUBLE__: ";
    #ifdef __SIZEOF_LONG_DOUBLE__
        cout << __SIZEOF_LONG_DOUBLE__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIZEOF_SIZE_T__: ";
    #ifdef __SIZEOF_SIZE_T__
        cout << __SIZEOF_SIZE_T__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIZEOF_WCHAR_T__: ";
    #ifdef __SIZEOF_WCHAR_T__
        cout << __SIZEOF_WCHAR_T__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIZEOF_WINT_T__: ";
    #ifdef __SIZEOF_WINT_T__
        cout << __SIZEOF_WINT_T__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SIZEOF_PTRDIFF_T__: ";
    #ifdef __SIZEOF_PTRDIFF_T__
        cout << __SIZEOF_PTRDIFF_T__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__BYTE_ORDER__: ";
    #ifdef __BYTE_ORDER__
        cout << __BYTE_ORDER__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__ORDER_LITTLE_ENDIAN__: ";
    #ifdef __ORDER_LITTLE_ENDIAN__
        cout << __ORDER_LITTLE_ENDIAN__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__ORDER_BIG_ENDIAN__: ";
    #ifdef __ORDER_BIG_ENDIAN__
        cout << __ORDER_BIG_ENDIAN__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__ORDER_PDP_ENDIAN__: ";
    #ifdef __ORDER_PDP_ENDIAN__
        cout << __ORDER_PDP_ENDIAN__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__FLOAT_WORD_ORDER__: ";
    #ifdef __FLOAT_WORD_ORDER__
        cout << __FLOAT_WORD_ORDER__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__DEPRECATED: ";
    #ifdef __DEPRECATED
        cout << __DEPRECATED;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__EXCEPTIONS: ";
    #ifdef __EXCEPTIONS
        cout << __EXCEPTIONS;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GXX_RTTI: ";
    #ifdef __GXX_RTTI
        cout << __GXX_RTTI;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__USING_SJLJ_EXCEPTIONS__: ";
    #ifdef __USING_SJLJ_EXCEPTIONS__
        cout << __USING_SJLJ_EXCEPTIONS__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GXX_EXPERIMENTAL_CXX0X__: ";
    #ifdef __GXX_EXPERIMENTAL_CXX0X__
        cout << __GXX_EXPERIMENTAL_CXX0X__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GXX_WEAK__: ";
    #ifdef __GXX_WEAK__
        cout << __GXX_WEAK__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__NEXT_RUNTIME__: ";
    #ifdef __NEXT_RUNTIME__
        cout << __NEXT_RUNTIME__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__LP64__: ";
    #ifdef __LP64__
        cout << __LP64__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "_LP64: ";
    #ifdef _LP64
        cout << _LP64;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SSP__: ";
    #ifdef __SSP__
        cout << __SSP__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SSP_ALL__: ";
    #ifdef __SSP_ALL__
        cout << __SSP_ALL__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SSP_EXPLICIT__: ";
    #ifdef __SSP_EXPLICIT__
        cout << __SSP_EXPLICIT__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SANITIZE_ADDRESS__: ";
    #ifdef __SANITIZE_ADDRESS__
        cout << __SANITIZE_ADDRESS__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__SANITIZE_THREAD__: ";
    #ifdef __SANITIZE_THREAD__
        cout << __SANITIZE_THREAD__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__TIMESTAMP__: ";
    #ifdef __TIMESTAMP__
        cout << __TIMESTAMP__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1: ";
    #ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1
        cout << __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2: ";
    #ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2
        cout << __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4: ";
    #ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4
        cout << __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8: ";
    #ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8
        cout << __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GCC_HAVE_SYNC_COMPARE_AND_SWAP_16: ";
    #ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_16
        cout << __GCC_HAVE_SYNC_COMPARE_AND_SWAP_16;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__HAVE_SPECULATION_SAFE_VALUE: ";
    #ifdef __HAVE_SPECULATION_SAFE_VALUE
        cout << __HAVE_SPECULATION_SAFE_VALUE;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GCC_HAVE_DWARF2_CFI_ASM: ";
    #ifdef __GCC_HAVE_DWARF2_CFI_ASM
        cout << __GCC_HAVE_DWARF2_CFI_ASM;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__FP_FAST_FMA: ";
    #ifdef __FP_FAST_FMA
        cout << __FP_FAST_FMA;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__FP_FAST_FMAF: ";
    #ifdef __FP_FAST_FMAF
        cout << __FP_FAST_FMAF;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__FP_FAST_FMAL: ";
    #ifdef __FP_FAST_FMAL
        cout << __FP_FAST_FMAL;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__FP_FAST_FMAF16: ";
    #ifdef __FP_FAST_FMAF16
        cout << __FP_FAST_FMAF16;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__FP_FAST_FMAF32: ";
    #ifdef __FP_FAST_FMAF32
        cout << __FP_FAST_FMAF32;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__FP_FAST_FMAF64: ";
    #ifdef __FP_FAST_FMAF64
        cout << __FP_FAST_FMAF64;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__FP_FAST_FMAF128: ";
    #ifdef __FP_FAST_FMAF128
        cout << __FP_FAST_FMAF128;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__FP_FAST_FMAF32X: ";
    #ifdef __FP_FAST_FMAF32X
        cout << __FP_FAST_FMAF32X;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__FP_FAST_FMAF64X: ";
    #ifdef __FP_FAST_FMAF64X
        cout << __FP_FAST_FMAF64X;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__FP_FAST_FMAF128X: ";
    #ifdef __FP_FAST_FMAF128X
        cout << __FP_FAST_FMAF128X;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GCC_IEC_559: ";
    #ifdef __GCC_IEC_559
        cout << __GCC_IEC_559;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GCC_IEC_559_COMPLEX: ";
    #ifdef __GCC_IEC_559_COMPLEX
        cout << __GCC_IEC_559_COMPLEX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__NO_MATH_ERRNO__: ";
    #ifdef __NO_MATH_ERRNO__
        cout << __NO_MATH_ERRNO__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__RECIPROCAL_MATH__: ";
    #ifdef __RECIPROCAL_MATH__
        cout << __RECIPROCAL_MATH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__NO_SIGNED_ZEROS__: ";
    #ifdef __NO_SIGNED_ZEROS__
        cout << __NO_SIGNED_ZEROS__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__NO_TRAPPING_MATH__: ";
    #ifdef __NO_TRAPPING_MATH__
        cout << __NO_TRAPPING_MATH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__ASSOCIATIVE_MATH__: ";
    #ifdef __ASSOCIATIVE_MATH__
        cout << __ASSOCIATIVE_MATH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__ROUNDING_MATH__: ";
    #ifdef __ROUNDING_MATH__
        cout << __ROUNDING_MATH__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GNUC_EXECUTION_CHARSET_NAME: ";
    #ifdef __GNUC_EXECUTION_CHARSET_NAME
        cout << __GNUC_EXECUTION_CHARSET_NAME;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GNUC_WIDE_EXECUTION_CHARSET_NAME: ";
    #ifdef __GNUC_WIDE_EXECUTION_CHARSET_NAME
        cout << __GNUC_WIDE_EXECUTION_CHARSET_NAME;
    #else
        cout << "undefined";
    #endif
    cout << "\n" << "\n";


    cout << "3. Compiler macros\n";
    cout << "__clang__: ";
    #ifdef __clang__
        cout << __clang__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__clang_major__: ";
    #ifdef __clang_major__
        cout << __clang_major__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__clang_minor__: ";
    #ifdef __clang_minor__
        cout << __clang_minor__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__clang_patchlevel__: ";
    #ifdef __clang_patchlevel__
        cout << __clang_patchlevel__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GNUC__: ";
    #ifdef __GNUC__
        cout << __GNUC__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GNUC_MINOR__: ";
    #ifdef __GNUC_MINOR__
        cout << __GNUC_MINOR__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__GNUC_PATCHLEVEL__: ";
    #ifdef __GNUC_PATCHLEVEL__
        cout << __GNUC_PATCHLEVEL__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "_MSC_VER: ";
    #ifdef _MSC_VER
        cout << _MSC_VER;
    #else
        cout << "undefined";
    #endif
    cout << "\n" << "\n";


    cout << "4. Platform-specific macros\n";
    cout << "_WIN32: ";
    #ifdef _WIN32
        cout << _WIN32;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "_WIN64: ";
    #ifdef _WIN64
        cout << _WIN64;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__linux__: ";
    #ifdef __linux__
        cout << __linux__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__unix__: ";
    #ifdef __unix__
        cout << __unix__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__APPLE__: ";
    #ifdef __APPLE__
        cout << __APPLE__;
    #else
        cout << "undefined";
    #endif
    cout << "\n" << "\n";


    cout << "5. Architecture-specific macros\n";
    cout << "__i386__: ";
    #ifdef __i386__
        cout << __i386__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__x86_64__: ";
    #ifdef __x86_64__
        cout << __x86_64__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "_M_IX86: ";
    #ifdef _M_IX86
        cout << _M_IX86;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "_M_X64: ";
    #ifdef _M_X64
        cout << _M_X64;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__arm__: ";
    #ifdef __arm__
        cout << __arm__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__aarch64__: ";
    #ifdef __aarch64__
        cout << __aarch64__;
    #else
        cout << "undefined";
    #endif
    cout << "\n" << "\n";


    cout << "6. Fundamental data types limits\n";
    cout << "CHAR_MIN: ";
    #ifdef CHAR_MIN
        cout << CHAR_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "CHAR_MAX: ";
    #ifdef CHAR_MAX
        cout << CHAR_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "SCHAR_MIN: ";
    #ifdef SCHAR_MIN
        cout << SCHAR_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "SCHAR_MAX: ";
    #ifdef SCHAR_MAX
        cout << SCHAR_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UCHAR_MAX: ";
    #ifdef UCHAR_MAX
        cout << UCHAR_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "SHRT_MIN: ";
    #ifdef SHRT_MIN
        cout << SHRT_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "SHRT_MAX: ";
    #ifdef SHRT_MAX
        cout << SHRT_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "USHRT_MAX: ";
    #ifdef USHRT_MAX
        cout << USHRT_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_MIN: ";
    #ifdef INT_MIN
        cout << INT_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_MAX: ";
    #ifdef INT_MAX
        cout << INT_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UINT_MAX: ";
    #ifdef UINT_MAX
        cout << UINT_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "LONG_MIN: ";
    #ifdef LONG_MIN
        cout << LONG_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "LONG_MAX: ";
    #ifdef LONG_MAX
        cout << LONG_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "ULONG_MAX: ";
    #ifdef ULONG_MAX
        cout << ULONG_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "LLONG_MIN: ";
    #ifdef LLONG_MIN
        cout << LLONG_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "LLONG_MAX: ";
    #ifdef LLONG_MAX
        cout << LLONG_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "ULLONG_MAX: ";
    #ifdef ULLONG_MAX
        cout << ULLONG_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "FLT_MIN: ";
    #ifdef FLT_MIN
        cout << FLT_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "FLT_MAX: ";
    #ifdef FLT_MAX
        cout << FLT_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "FLT_DIG: ";
    #ifdef FLT_DIG
        cout << FLT_DIG;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "DBL_MIN: ";
    #ifdef DBL_MIN
        cout << DBL_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "DBL_MAX: ";
    #ifdef DBL_MAX
        cout << DBL_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "DBL_DIG: ";
    #ifdef DBL_DIG
        cout << DBL_DIG;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "LDBL_MIN: ";
    #ifdef LDBL_MIN
        cout << LDBL_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "LDBL_MAX: ";
    #ifdef LDBL_MAX
        cout << LDBL_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "LDBL_DIG: ";
    #ifdef LDBL_DIG
        cout << LDBL_DIG;
    #else
        cout << "undefined";
    #endif
    cout << "\n" << "\n";


    cout << "7. Fixed width integer data types limits\n";
    cout << "INT8_MIN: ";
    #ifdef INT8_MIN
        cout << INT8_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT16_MIN: ";
    #ifdef INT16_MIN
        cout << INT16_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT32_MIN: ";
    #ifdef INT32_MIN
        cout << INT32_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT64_MIN: ";
    #ifdef INT64_MIN
        cout << INT64_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_FAST8_MIN: ";
    #ifdef INT_FAST8_MIN
        cout << INT_FAST8_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_FAST16_MIN: ";
    #ifdef INT_FAST16_MIN
        cout << INT_FAST16_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_FAST32_MIN: ";
    #ifdef INT_FAST32_MIN
        cout << INT_FAST32_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_FAST64_MIN: ";
    #ifdef INT_FAST64_MIN
        cout << INT_FAST64_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_LEAST8_MIN: ";
    #ifdef INT_LEAST8_MIN
        cout << INT_LEAST8_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_LEAST16_MIN: ";
    #ifdef INT_LEAST16_MIN
        cout << INT_LEAST16_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_LEAST32_MIN: ";
    #ifdef INT_LEAST32_MIN
        cout << INT_LEAST32_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_LEAST64_MIN: ";
    #ifdef INT_LEAST64_MIN
        cout << INT_LEAST64_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INTPTR_MIN: ";
    #ifdef INTPTR_MIN
        cout << INTPTR_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INTMAX_MIN: ";
    #ifdef INTMAX_MIN
        cout << INTMAX_MIN;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT8_MAX: ";
    #ifdef INT8_MAX
        cout << INT8_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT16_MAX: ";
    #ifdef INT16_MAX
        cout << INT16_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT32_MAX: ";
    #ifdef INT32_MAX
        cout << INT32_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT64_MAX: ";
    #ifdef INT64_MAX
        cout << INT64_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_FAST8_MAX: ";
    #ifdef INT_FAST8_MAX
        cout << INT_FAST8_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_FAST16_MAX: ";
    #ifdef INT_FAST16_MAX
        cout << INT_FAST16_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_FAST32_MAX: ";
    #ifdef INT_FAST32_MAX
        cout << INT_FAST32_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_FAST64_MAX: ";
    #ifdef INT_FAST64_MAX
        cout << INT_FAST64_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_LEAST8_MAX: ";
    #ifdef INT_LEAST8_MAX
        cout << INT_LEAST8_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_LEAST16_MAX: ";
    #ifdef INT_LEAST16_MAX
        cout << INT_LEAST16_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_LEAST32_MAX: ";
    #ifdef INT_LEAST32_MAX
        cout << INT_LEAST32_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INT_LEAST64_MAX: ";
    #ifdef INT_LEAST64_MAX
        cout << INT_LEAST64_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INTPTR_MAX: ";
    #ifdef INTPTR_MAX
        cout << INTPTR_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "INTMAX_MAX: ";
    #ifdef INTMAX_MAX
        cout << INTMAX_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UINT8_MAX: ";
    #ifdef UINT8_MAX
        cout << UINT8_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UINT16_MAX: ";
    #ifdef UINT16_MAX
        cout << UINT16_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UINT32_MAX: ";
    #ifdef UINT32_MAX
        cout << UINT32_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UINT64_MAX: ";
    #ifdef UINT64_MAX
        cout << UINT64_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UINT_FAST8_MAX: ";
    #ifdef UINT_FAST8_MAX
        cout << UINT_FAST8_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UINT_FAST16_MAX: ";
    #ifdef UINT_FAST16_MAX
        cout << UINT_FAST16_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UINT_FAST32_MAX: ";
    #ifdef UINT_FAST32_MAX
        cout << UINT_FAST32_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UINT_FAST64_MAX: ";
    #ifdef UINT_FAST64_MAX
        cout << UINT_FAST64_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UINT_LEAST8_MAX: ";
    #ifdef UINT_LEAST8_MAX
        cout << UINT_LEAST8_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UINT_LEAST16_MAX: ";
    #ifdef UINT_LEAST16_MAX
        cout << UINT_LEAST16_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UINT_LEAST32_MAX: ";
    #ifdef UINT_LEAST32_MAX
        cout << UINT_LEAST32_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UINT_LEAST64_MAX: ";
    #ifdef UINT_LEAST64_MAX
        cout << UINT_LEAST64_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UINTPTR_MAX: ";
    #ifdef UINTPTR_MAX
        cout << UINTPTR_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "UINTMAX_MAX: ";
    #ifdef UINTMAX_MAX
        cout << UINTMAX_MAX;
    #else
        cout << "undefined";
    #endif
    cout << "\n" << "\n";


    cout << "8. Function macros for minimum-width integer constants\n";
    cout << "INT8_C: ";
//    #ifdef INT8_C
//        cout << INT8_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "INT16_C: ";
//    #ifdef INT16_C
//        cout << INT16_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "INT32_C: ";
//    #ifdef INT32_C
//        cout << INT32_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "INT64_C: ";
//    #ifdef INT64_C
//        cout << INT64_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "INTMAX_C: ";
//    #ifdef INTMAX_C
//        cout << INTMAX_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "UINT8_C: ";
//    #ifdef UINT8_C
//        cout << UINT8_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "UINT16_C: ";
//    #ifdef UINT16_C
//        cout << UINT16_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "UINT32_C: ";
//    #ifdef UINT32_C
//        cout << UINT32_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "UINT64_C: ";
//    #ifdef UINT64_C
//        cout << UINT64_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "UINTMAX_C: ";
//    #ifdef UINTMAX_C
//        cout << UINTMAX_C;
//    #else
//        cout << "undefined";
//    #endif
    cout << "\n";

    cout << "UINT64_C(0x123): ";
    #ifdef UINT64_C
        cout << UINT64_C(0x123);
    #else
        cout << "undefined";
    #endif
    cout << "\n" << "\n";


    cout << "9. Other predefined macros\n";
    cout << "__FLT_EPSILON__: ";
    #ifdef __FLT_EPSILON__
        cout << __FLT_EPSILON__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__STDC_ISO_10646__: ";
    #ifdef __STDC_ISO_10646__
        cout << __STDC_ISO_10646__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__STDC_MB_MIGHT_NEQ_WC__: ";
    #ifdef __STDC_MB_MIGHT_NEQ_WC__
        cout << __STDC_MB_MIGHT_NEQ_WC__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__STDC_UTF_16__: ";
    #ifdef __STDC_UTF_16__
        cout << __STDC_UTF_16__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__STDC_UTF_32__: ";
    #ifdef __STDC_UTF_32__
        cout << __STDC_UTF_32__;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__cpp_exceptions: ";
    #ifdef __cpp_exceptions
        cout << __cpp_exceptions;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    cout << "__cpp_rtti: ";
    #ifdef __cpp_rtti
        cout << __cpp_rtti;
    #else
        cout << "undefined";
    #endif
    cout << "\n";

    return 0;
}

#include <catch2/catch_test_macros.hpp>
#include <cstddef>
#include <type_traits>

template<typename ... Types>
struct get_first_type{
    using type = void;
};

template<typename FIRST,typename ... Types>
struct get_first_type<FIRST,Types...>{
    using type = FIRST;
};


TEST_CASE("Empty"){  
    REQUIRE( std::is_same_v<get_first_type<>::type, void> );
}

TEST_CASE("Double"){
    REQUIRE( std::is_same_v<get_first_type<double,void,int>::type, double> );
}

TEST_CASE("float"){
    REQUIRE_FALSE( std::is_same_v<get_first_type<float,void,int>::type, double> );
}



template <typename NEEDLE,typename ... Types>
struct index_of_type{
    static_assert(sizeof...(Types)>0,"You mast pass at least one type" );
};

template <typename NEEDLE, typename ... Types>
struct index_of_type<NEEDLE,NEEDLE,  Types...>{
    static constexpr size_t index = 0;
};

template <typename NEEDLE, typename HEAD,typename ... Types>
struct index_of_type<NEEDLE,HEAD,  Types...>{
    static constexpr size_t index = 1+index_of_type<NEEDLE, Types...>::index;
};


TEST_CASE("int0"){
    REQUIRE(index_of_type<int,int>::index == 0);
}

TEST_CASE("int0_again"){
    REQUIRE(index_of_type<int,int,char>::index == 0);
}

TEST_CASE("int1"){
    REQUIRE(index_of_type<int,double,int>::index == 1);
}

TEST_CASE("int3"){
    REQUIRE(index_of_type<int,double,long,char,int>::index == 3);
}
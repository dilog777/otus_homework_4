/*!
\file
\brief Helper functions for defining std containers
*/

#include <type_traits>


template<typename...>
struct is_container_helper {};



template<typename T, typename _ = void>
struct is_container : std::false_type {};



template<typename T>
struct is_container
<
	T,
	std::conditional_t
	<
		false,
		is_container_helper
		<
			typename T::value_type,
			typename T::size_type,
			typename T::iterator,
			typename T::const_iterator,
			decltype(std::declval<T>().size()),
			decltype(std::declval<T>().begin()),
			decltype(std::declval<T>().end()),
			decltype(std::declval<T>().cbegin()),
			decltype(std::declval<T>().cend())
		>,
		void
	>
> : public std::true_type{};



template <typename T>
constexpr bool is_container_v = is_container<T>::value;

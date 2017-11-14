#pragma once

namespace LiteSTL
{

	struct TrueType {};
	struct FalseType {};
	/***********************************************************/
	/*					萃取传入的T的类型特性					   */
	/***********************************************************/
	template<typename T>
	struct TypeTraits
	{
		using HasTrivialDefaultConstructor	= FalseType;
		using HasTrivialCopyConstructor		= FalseType;
		using HasTrivialAssignmentOperator	= FalseType;
		using HasTrivialDestructor			= FalseType;
		using IsPODType						= FalseType;
	};

	template<>
	struct TypeTraits<bool>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<char>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<unsigned char>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<signed char>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<wchar_t>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<short>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<unsigned short>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<int>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<unsigned int>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<long>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<unsigned long>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<long long>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<unsigned long long>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<float>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<double>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<long double>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<typename T>
	struct TypeTraits<T* >
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<typename T>
	struct TypeTraits<const T*>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstructor		= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestrucotr			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<char*>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstrucotor	= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<unsigned char*>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstrucotor	= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<signed char*>
	{
		using HasTrivialDefaultConstructor	= TrueType;
		using HasTrivialCopyConstrucotor	= TrueType;
		using HasTrivialAssignmentOperator	= TrueType;
		using HasTrivialDestructor			= TrueType;
		using IsPODType						= TrueType;
	};

	template<>
	struct TypeTraits<const char*>
	{
		using HasTrivialDefaultConstructor = TrueType;
		using HasTrivialCopyConstrucotor = TrueType;
		using HasTrivialAssignmentOperator = TrueType;
		using HasTrivialDestructor = TrueType;
		using IsPODType = TrueType;
	};

	template<>
	struct TypeTraits<const unsigned char*>
	{
		using HasTrivialDefaultConstructor = TrueType;
		using HasTrivialCopyConstrucotor = TrueType;
		using HasTrivialAssignmentOperator = TrueType;
		using HasTrivialDestructor = TrueType;
		using IsPODType = TrueType;
	};

	template<>
	struct TypeTraits<const signed char*>
	{
		using HasTrivialDefaultConstructor = TrueType;
		using HasTrivialCopyConstrucotor = TrueType;
		using HasTrivialAssignmentOperator = TrueType;
		using HasTrivialDestructor = TrueType;
		using IsPODType = TrueType;
	};

	/****************************************************************/
	/*                          整数类型判断                          */
	/****************************************************************/
	template<typename T>
	struct IsIntegral
	{
		using Type = FalseType;
	};

	template<>
	struct IsIntegral<bool>
	{
		using Type = TrueType;
	};

	template<>
	struct IsIntegral<char>
	{
		using Type = TrueType;
	};

	template<>
	struct IsIntegral<unsigned char>
	{
		using Type = TrueType;
	};

	template<>
	struct IsIntegral<signed char>
	{
		using Type = TrueType;
	};

#ifdef _NATIVE_WCHAR_T_DEFINED
	template<>
	struct IsIntegral<wchar_t>
	{
		using Type = TrueType;
	};
#endif

#ifdef _HAS_CHAR16_T_LANGUAGE_SUPPORT
	template<>
	struct IsIntegral<char16_t>
	{
		using Type = TrueType;
	};

	template<>
	struct IsIntegral<char32_t>
	{
		using Type = TrueType;
	};
#endif

	template<>
	struct IsIntegral<short>
	{
		using Type = TrueType;
	};

	template<>
	struct IsIntegral<unsigned short>
	{
		using Type = TrueType;
	};

	template<>
	struct IsIntegral<int>
	{
		using Type = TrueType;
	};

	template<>
	struct IsIntegral<unsigned int>
	{
		using Type = TrueType;
	};

	template<>
	struct IsIntegral<long>
	{
		using Type = TrueType;
	};

	template<>
	struct IsIntegral<unsigned long>
	{
		using Type = TrueType;
	};

#ifdef _LONGLONG
	template<>
	struct IsIntegral<long long>
	{
		using Type = TrueType;
	};

	template<>
	struct IsIntegral<unsigned long long>
	{
		using Type = TrueType;
	};
#endif
}
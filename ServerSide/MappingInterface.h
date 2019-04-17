#pragma once
#include "pch.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::shared_ptr;

class FieldInterface
	{
	protected:
		void* value;
	public:
		virtual			~FieldInterface() {};
		virtual string*	getValueAsString() = 0;
		virtual void*	getValue() = 0;
		virtual void	setValue(void*) = 0;
		virtual string*	getColumnName() = 0;
	};


template <typename T>
	class FieldTemplate
		: public FieldInterface
	{
	public:
		~FieldTemplate() { delete value; }
		void	setValue(void* value) override { this->value = value; }
		void*	getValue() override
		{
			return static_cast<T*>(value);
		}
		string* getValueAsString() override
		{
			std::stringstream StringStream;
			T* TypedValue = static_cast<T*>(value);
			StringStream << *TypedValue;
			return new string(StringStream.str());
		}

	};


template <typename T>
	class FieldInstance
		: public FieldTemplate<T>
	{
		static string name;
	public:
		FieldInstance(string name, T& value)
		{
			FieldInstance::name = name;
			this->setValue(&value);
		}

		string* getColumnName() { return &FieldInstance::name; }

	};

template <typename T>
string FieldInstance<T>::name;

	class EntityInterface
	{
	protected:
		vector<FieldInterface*> fieldsVector;
	public:
		vector<FieldInterface*>* getFieldsVector() { return &fieldsVector; }

		template<typename T>
		T* getValue(unsigned short index)	
		{ 
			if (index < fieldsVector.size())
			{
				return static_cast<T*>(fieldsVector[index]->getValue());
			}
			else
			{
				return nullptr;
			}
		}
		virtual string getTableName() = 0;
	};

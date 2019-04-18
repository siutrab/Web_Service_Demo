#pragma once
#include "pch.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using std::vector;
using std::string;
using std::stringstream;
using std::unique_ptr;

class FieldInterface
	{
	public:
		virtual			~FieldInterface() {};
		virtual unique_ptr<string>	getValueAsString() = 0;
		virtual void*	getValuePtr() = 0;
		virtual void	setValue(void*) = 0;
		virtual string*	getColumnName() = 0;
	};


template <typename T>
	class FieldTemplate
		: public FieldInterface
	{
	protected:
		T storedValue;
	public:
		~FieldTemplate() { }
		void	setValue(void* value) override 
		{ 
			storedValue = *(static_cast<T*>(value));
		}
		void*	getValuePtr() override
		{
			return &storedValue;
		}
		T getValue()
		{ 
			return storedValue; 
		}
		unique_ptr<string> getValueAsString() override
		{
			unique_ptr<string> str(new string());
			stringstream StringStream;

			StringStream << std::fixed << storedValue;

			*str = StringStream.str();
			
			return str;
		}

	};


template <typename T>
	class FieldInstance
		: public FieldTemplate<T>
	{
		static string name;
	public:
		FieldInstance(string name, T* value)
		{
			FieldInstance::name = name;
			this->setValue(value);
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

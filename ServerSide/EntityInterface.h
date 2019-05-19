#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <memory>

using std::vector;
using std::string;
using std::unique_ptr;


class FieldInterface
	{
	public:
		virtual			~FieldInterface() {};
		virtual unique_ptr<string>	getValueAsString() = 0;
		virtual unique_ptr<string>	getColumnName() = 0;
		virtual void*	getValuePtr() = 0;
		virtual void	setValue(void*) = 0;
	};


template <typename T>
	class FieldTemplate
		: public FieldInterface
	{
	protected:
		T storedValue;
	public:
		FieldTemplate(T &value)	{ storedValue = value; }

		~FieldTemplate() { }

		void setValue(void* value) override	
		{ 
			storedValue = *(static_cast<T*>(value)); 
		}

		void* getValuePtr() override
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
			std::stringstream StringStream;

			StringStream << std::fixed << storedValue;

			*str = StringStream.str();	
			return str;
		}
	};


class EntityInterface
{
protected:
	vector<unique_ptr<FieldInterface>> fieldsVector;
public:
	vector<unique_ptr<FieldInterface>>* getFieldsVector() { return &fieldsVector; }

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

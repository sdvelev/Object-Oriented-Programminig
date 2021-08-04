#include "Error.hpp"

bool Error::hasMessage() const {
	if (this->error_type == ErrorType::None) {
		return false;
	}
	else {
		return true;
	}
}

const char* Error::getMessage() const {
	const char a[1] = {'\0'};
	if (this->hasMessage()) {
		return this->message;
	}
	else {
		return a;
	}
}

ErrorType Error::getType() const {
	return this->error_type;
}

 Error Error::newNone() {
	 Error new_none;
	 return new_none;
}

 Error Error::newBuildFailed(const char* message) {
	 Error new_buildfailed;
	 new_buildfailed.error_type = ErrorType::BuildFailed;
	 char* new_message = new char[strlen(message) + 1];
	 strcpy(new_message, message);

	 new_buildfailed.message = new_message;
	 return new_buildfailed;
 }

 Error Error::newWarning(const char* message) {
	 Error new_warning;
	 new_warning.error_type = ErrorType::Warning;
	 char* new_message = new char[strlen(message) + 1];
	 strcpy(new_message, message);
	 new_warning.message = new_message;
	 return new_warning;
 }

 Error Error::newFailedAssertion(const char* message) {
	 Error new_failedassertion;
	 new_failedassertion.error_type = ErrorType::FailedAssertion;
	 char* new_message = new char[strlen(message) + 1];
	 strcpy(new_message, message);
	 new_failedassertion.message = new_message;
	 return new_failedassertion;
 }

 Error::Error() {
	 this->error_type = ErrorType::None;
	 this->message = nullptr;
 }

 Error::Error(const Error& other) {
	 this->error_type = other.error_type;
	 if (other.message == nullptr) {
		 this->message = new char[1];
		 this->message[0] = '\0';
	 }
	 else {
		 this->message = new char[strlen(other.message) + 1];
		 strcpy(this->message, other.message);
	 }	
 }

 Error&	Error::operator=(const Error& other) {
	 if (this != &other) {
		 delete[] this->message;
		 this->message = new char[strlen(other.message) + 1];
		 strcpy(this->message, other.message);
		 this->error_type = other.error_type;
	 }
	 return *this;
 }

Error::~Error() {
	 delete[] this->message;
 }


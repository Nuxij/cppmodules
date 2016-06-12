#pragma once

#include <string>

#include "main/messages/uri.hpp"

using namespace std;

namespace cppm { namespace messages {
	class MUri {
		public:
			MUri(){};
			MUri(const string& inuri) {
				setUri(inuri);
			};
			MUri(const string& mod, const string& dom, const string& com) {
				module(mod);
				domain(dom);
				command(com);
			};

			const string module() {
				return uri.scheme();
			};

			const string domain() {
				return uri.host();
			};

			const string command() {
				auto c = uri.path();
				if (strcmp(&c[0], "/"))
					return c.substr(1);
				return c;
			};

			const map<string, list<string>>& params() {
				return uri.getQueryParams();
			};

			void module(const string& mod) {
				uri.scheme(mod);
			};

			void domain(const string& dom) {
				uri.host(dom);
			};

			void command(string com) {
				if (strncmp(com.c_str(), "/", 1))
					com = "/" + com;
				uri.path(com);
			};

			const list<string>& param(const string& key) {
				return uri.getQueryParam(key);
			}

			void param(const string& key, const string& value) {
				uri.addQueryParam(key, value);
			};

			string getUri() const {
				return uri.toString();
			};

			void setUri(const string& inuri) {
				uri.parseUri(inuri);
			};

		private:
			Uri uri;
	};
}}

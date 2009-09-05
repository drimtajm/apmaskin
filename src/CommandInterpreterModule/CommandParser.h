/*
 * CommandParser.h
 *
 *  Created on: 2009-sep-05
 *      Author: bege
 */

#ifndef COMMANDPARSER_H_
#define COMMANDPARSER_H_

#include <boost/spirit/core.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::spirit;

class DoCmd {
public:
	DoCmd(string& command) : command(command) {}

	template<typename T>
	void operator() (T first, T end) const {
		command = string(first, end);
	}
	string& command;
};

class DoParameter {
public:
	DoParameter(vector<int>& parameters) : parameters(parameters) { }

	template<typename T>
	void operator() (T val) const {
		parameters.push_back(val);
	}
	vector<int>& parameters;
};

/**
 * The command grammar
 */
struct CommandParser: public grammar<CommandParser>
{
	CommandParser(string& command, vector<int>& parameters) : command(command), parameters(parameters) {}
    template <typename ScannerT>
    struct definition
    {
        definition(CommandParser const& self)
        {
            expression
                =   cmd[DoCmd(self.command)] >> !argList
                ;
            cmd
				=	lexeme_d[*(alnum_p)]
				;
            argList
				=	int_p[DoParameter(self.parameters)] >> *(',' >> int_p[DoParameter(self.parameters)])
				;

        }

        rule<ScannerT> expression, cmd, argList;
        rule<ScannerT> const& start() const { return expression; }
    };
	string& command;
	vector<int>& parameters;
};
#endif

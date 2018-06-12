//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "capybaraTestApp.h"
#include "capybaraApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<capybaraTestApp>()
{
  InputParameters params = validParams<capybaraApp>();
  return params;
}

capybaraTestApp::capybaraTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  capybaraApp::registerObjectDepends(_factory);
  capybaraApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  capybaraApp::associateSyntaxDepends(_syntax, _action_factory);
  capybaraApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  capybaraApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    capybaraTestApp::registerObjects(_factory);
    capybaraTestApp::associateSyntax(_syntax, _action_factory);
    capybaraTestApp::registerExecFlags(_factory);
  }
}

capybaraTestApp::~capybaraTestApp() {}

void
capybaraTestApp::registerApps()
{
  registerApp(capybaraApp);
  registerApp(capybaraTestApp);
}

void
capybaraTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
capybaraTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
capybaraTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
capybaraTestApp__registerApps()
{
  capybaraTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
capybaraTestApp__registerObjects(Factory & factory)
{
  capybaraTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
capybaraTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  capybaraTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
capybaraTestApp__registerExecFlags(Factory & factory)
{
  capybaraTestApp::registerExecFlags(factory);
}

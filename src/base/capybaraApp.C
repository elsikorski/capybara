#include "capybaraApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<capybaraApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

capybaraApp::capybaraApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  capybaraApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  capybaraApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  capybaraApp::registerExecFlags(_factory);
}

capybaraApp::~capybaraApp() {}

void
capybaraApp::registerApps()
{
  registerApp(capybaraApp);
}

void
capybaraApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"capybaraApp"});
}

void
capybaraApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"capybaraApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
capybaraApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
capybaraApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
capybaraApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
capybaraApp__registerApps()
{
  capybaraApp::registerApps();
}

extern "C" void
capybaraApp__registerObjects(Factory & factory)
{
  capybaraApp::registerObjects(factory);
}

extern "C" void
capybaraApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  capybaraApp::associateSyntax(syntax, action_factory);
}

extern "C" void
capybaraApp__registerExecFlags(Factory & factory)
{
  capybaraApp::registerExecFlags(factory);
}

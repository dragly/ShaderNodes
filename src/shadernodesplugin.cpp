#include "shadernodesplugin.h"

#include "shaderbuilder.h"
#include "shaderbuilderbinding.h"
#include "shadernode.h"
#include "shaderoutput.h"
#include "shaderutils.h"

#include <qqml.h>
#include <QQmlEngine>

static const char* packageUri = "ShaderNodes";

void ShaderNodesPlugin::registerTypes(const char *uri)
{
    Q_INIT_RESOURCE(shadernodes_imports);
    Q_ASSERT(uri == QLatin1String(packageUri));
    qmlRegisterType<ShaderNode>(packageUri, 1, 0, "ShaderNode");
    qmlRegisterType<ShaderBuilder>(packageUri, 1, 0, "ShaderBuilder");
    qmlRegisterType<ShaderOutput>(packageUri, 1, 0, "ShaderOutput");
    qmlRegisterType<ShaderBuilderBinding>(packageUri, 1, 0, "ShaderBuilderBinding");

    qmlRegisterSingletonType<ShaderUtils>(packageUri, 1, 0, "ShaderUtils", &ShaderUtils::qmlInstance);
}

void ShaderNodesPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    Q_UNUSED(engine);
    Q_UNUSED(uri);
}
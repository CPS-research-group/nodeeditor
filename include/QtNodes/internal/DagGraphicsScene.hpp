#pragma once

#include <QFileInfo>
#include <QDir>

#include "BasicGraphicsScene.hpp"
#include "DirectedAcyclicGraphModel.hpp"
#include "Export.hpp"

namespace QtNodes {

/// @brief An advanced scene working with data-propagating graphs.
/**
 * The class represents a scene that existed in v2.x but built wit the
 * new model-view approach in mind.
 */
class NODE_EDITOR_PUBLIC DagGraphicsScene : public BasicGraphicsScene
{
    Q_OBJECT
public:
    DagGraphicsScene(DirectedAcyclicGraphModel &graphModel, QObject *parent = nullptr);
    ~DagGraphicsScene() = default;
    std::vector<NodeId> selectedNodes() const;
    QMenu *createSceneMenu(QPointF const scenePos) override;
    bool isEmpty() const { return _graphModel.isEmpty(); }
    bool isBlank() const { return _graphModel.isEmpty(); }
    QDir getDataDir() const;
    void setDataDir(QDir const &dir);

public Q_SLOTS:
    bool save(const QString &filePath, const QJsonObject &metadata = {}) const;
    bool load(const QString &filePath);
    void createNodeAt(const QString &name, const QPointF &pos);

Q_SIGNALS:
    void sceneLoaded();

private:
    DirectedAcyclicGraphModel &_graphModel;
    QDir _dataDir; // store current tab's data dir
};

} // namespace QtNodes

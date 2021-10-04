#ifndef CUTTINGMATERIAL_H
#define CUTTINGMATERIAL_H

#include "fragmentmodel.h"

#include <QObject>

struct Material {
    double m_width;
    double m_height;
};

class CuttingMaterial : public QObject {
    Q_OBJECT
public:
    explicit CuttingMaterial(QObject* parent = nullptr);

    FragmentModel* getFragmentModel();

    void addFragment();

private:
    FragmentModel m_fragmentModel;
    std::vector<Fragment> m_fragments;
signals:
};

#endif // CUTTINGMATERIAL_H

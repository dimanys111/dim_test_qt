#include "cuttingmaterial.h"

CuttingMaterial::CuttingMaterial(QObject* parent)
    : QObject(parent)
    , m_fragmentModel(&m_fragments)
{
    m_fragments.emplace_back();
    m_fragments.emplace_back();
    m_fragments.emplace_back();
}

FragmentModel* CuttingMaterial::getFragmentModel()
{
    return &m_fragmentModel;
}

void CuttingMaterial::addFragment()
{
    m_fragments.emplace_back();
    m_fragmentModel.needReset();
}

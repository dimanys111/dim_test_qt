#include "fragmentmodel.h"

FragmentModel::FragmentModel(std::vector<Fragment>* fragments, QObject* parent)
    : QAbstractTableModel(parent)
    , m_fragments(fragments)

{
}

int FragmentModel::rowCount(const QModelIndex& parent) const
{
    return m_fragments->size();
}

int FragmentModel::columnCount(const QModelIndex& parent) const
{
    return 4;
}

QVariant FragmentModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole) {
        QString result;
        switch (index.column()) {
        case NAME:
            result = m_fragments->at(index.row()).m_name;
            break;
        case COUNT:
            result = m_fragments->at(index.row()).m_count;
            break;
        case WIDTH:
            result = m_fragments->at(index.row()).m_width;
            break;
        case HEIGHT:
            result = m_fragments->at(index.row()).m_height;
            break;
        default:
            break;
        }
        return result;
    }

    return QVariant();
}

bool FragmentModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (role == Qt::EditRole) {
        if (!checkIndex(index))
            return false;
        switch (index.column()) {
        case NAME:
            m_fragments->at(index.row()).m_name = value.toString();
            break;
        case COUNT:
            m_fragments->at(index.row()).m_count = value.toString().toInt();
            break;
        case WIDTH:
            m_fragments->at(index.row()).m_width = value.toString().toDouble();
            break;
        case HEIGHT:
            m_fragments->at(index.row()).m_height = value.toString().toDouble();
            break;
        default:
            break;
        }
        QModelIndex topLeft = createIndex(index.row(), 0);
        QModelIndex bottomRight = createIndex(index.row(), 3);
        emit dataChanged(topLeft, bottomRight, { Qt::DisplayRole });
        return true;
    }
    return false;
}

QVariant FragmentModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case NAME:
            return QString("Название");
        case COUNT:
            return QString("Количество");
        case WIDTH:
            return QString("Ширина");
        case HEIGHT:
            return QString("Высота");
        }
    }
    return QVariant();
}

Qt::ItemFlags FragmentModel::flags(const QModelIndex& index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

void FragmentModel::needReset()
{
    QModelIndex topLeft = createIndex(0, 0);
    QModelIndex bottomRight = createIndex(m_fragments->size() - 1, 3);
    emit dataChanged(topLeft, bottomRight, { Qt::DisplayRole });
}

#ifndef FRAGMENTMODEL_H
#define FRAGMENTMODEL_H

#include <QAbstractTableModel>

enum RowName {
    NAME = 0,
    COUNT,
    WIDTH,
    HEIGHT
};

struct Fragment {
    QString m_name;
    int m_count;
    double m_width;
    double m_height;
    int m_x;
    int m_y;
};

class FragmentModel : public QAbstractTableModel {
    Q_OBJECT
public:
    FragmentModel(std::vector<Fragment>* fragments, QObject* parent = nullptr);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    void needReset();

private:
    std::vector<Fragment>* m_fragments;
};

#endif // FRAGMENTMODEL_H

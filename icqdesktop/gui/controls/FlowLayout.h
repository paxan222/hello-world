#pragma once

namespace Ui
{
	class FlowLayout : public QLayout
	{
	public:

		explicit FlowLayout(QWidget* _parent, int _margin = -1, int _h_spacing = -1, int _v_spacing = -1);
		explicit FlowLayout(int _margin = -1, int _h_spacing = -1, int _v_spacing = -1);
		~FlowLayout();

		void addItem(QLayoutItem* _item) Q_DECL_OVERRIDE;
		int horizontalSpacing() const;
		int verticalSpacing() const;
		Qt::Orientations expandingDirections() const Q_DECL_OVERRIDE;
		bool hasHeightForWidth() const Q_DECL_OVERRIDE;
		int heightForWidth(int) const Q_DECL_OVERRIDE;
		int count() const Q_DECL_OVERRIDE;
		QLayoutItem *itemAt(int _index) const Q_DECL_OVERRIDE;
		QSize minimumSize() const Q_DECL_OVERRIDE;
		void setGeometry(const QRect &rect) Q_DECL_OVERRIDE;
		QSize sizeHint() const Q_DECL_OVERRIDE;
		QLayoutItem *takeAt(int _index) Q_DECL_OVERRIDE;

	private:

		int doLayout(const QRect& _rect, bool _testOnly) const;
		int smartSpacing(QStyle::PixelMetric _pm) const;

		QList<QLayoutItem *>	item_list_;
		int						h_space_;
		int						v_space_;
	};

}